/*
 SMG
 By Liyanboy74
 https://github.com/liyanboy74/smg
*/

#include <stdio.h>
#include <string.h>
#include <argp.h>

char *SITE_NAME=(char*)&"https://site.com";
char DIR[256];
char BUFFER[512];

FILE *fs;
char *file_name=(char*)&"sitemap.xml";
int status=0;

int link_c=0;

const char * XML_HEADER=(char*)&\
"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n\
<urlset xmlns=\"http://www.sitemaps.org/schemas/sitemap/0.9\">\n";
const char * XML_FOOTER=(char*)&"</urlset>\n";

int add_link(char *Buffer)
{
    if(!status)
    {
        fs=fopen(file_name,"w");
        if(fs)
        {
            status++;
            fwrite(XML_HEADER,strlen(XML_HEADER),1,fs);
            return(add_link(SITE_NAME)|add_link(Buffer));
        }
        else
        {
            printf("ERROR: Can't open [%s] file!\n",file_name);
            return -1;
        }
    }
    else
    {
        fwrite("\t<url>\n",7,1,fs);

        fwrite("\t\t<loc>",7,1,fs);
        fwrite(Buffer,strlen(Buffer),1,fs);
        fwrite("</loc>\n",7,1,fs);

        fwrite("\t</url>\n",8,1,fs);

        printf("%03d: %s\n",++link_c,Buffer);
    }
    return 0;
}

void check_file()
{
    if(status)
    {
        fwrite(XML_FOOTER,strlen(XML_FOOTER),1,fs);
        fclose(fs);
        printf("Output: %s\n",file_name);
    }
}

static int parse_opt(int key,char *arg,struct argp_state *state)
{
    switch(key)
    {
        case 's':SITE_NAME=arg;break;
        case 'd':
        {
            sprintf(DIR,"%s/%s",SITE_NAME,arg);
            return add_link(DIR);
        }
        case 'n':
        {
            file_name=arg;
            break;
        }
        case 'p':
        {
            sprintf(BUFFER,"%s/%s",DIR,arg);
            return add_link(BUFFER);
        }
        case ARGP_KEY_ARG:
        {
            return parse_opt('p',arg,state);
        }
        case ARGP_KEY_END:
        {
            check_file();
            break;
        }
        case ARGP_KEY_INIT:
        {
            sprintf(DIR,"%s",SITE_NAME);
            break;
        }
    }
    return 0;
}

int main(int argc,char **argv)
{
    struct argp_option option[]=
    {
        {"site",'s',"SITE",0,"site address"},
        {"post",'p',"POST",0,"add post"},
        {"dir",'d',"DIR",0,"change dir"},
        {"name",'n',"FILE",0,"rename output file"},
        {0}
    };
    struct argp argp={option,parse_opt,"SMG - Site Map Generator","Example: smg -s test.com -d blog -p help"};
    return argp_parse(&argp,argc,argv,0,0,0);
}
