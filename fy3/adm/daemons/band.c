// �޸�---��������(xgchen) ------fy-xgchen@163.com----2002.2-----

// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// ban.c


#define BANNED_SITES "/adm/etc/banned_sites"
#define ALLOWED_SITES "/adm/etc/allowed_sites"
void load_sites();
void add(string pattern);
void delete(string pattern);
int  is_banned(string site);
void print();

string *Sites;
string *OKSites;
void create()
{
	seteuid(getuid());
	load_sites();
}

void load_sites()
{
	string *tmp, file;
	int loop;

	Sites = ({});
	OKSites = ({});	
	// reads in the list of the banned sites

	file = read_file(BANNED_SITES);
	if (!file) return;
	
	tmp = explode(file, "\n");
   	for(loop=0; loop<sizeof(tmp); loop++)
        	if(tmp[loop][0] == '#' || tmp[loop][0] == '\n' || tmp[loop] == "")
           		continue;
        	else Sites += ({ tmp[loop] });

        // reads in the list of the allowed sites
        file = read_file(ALLOWED_SITES);
        if (!file) return;

        tmp = explode(file, "\n");
        for(loop=0; loop<sizeof(tmp); loop++)
                if(tmp[loop][0] == '#' || tmp[loop][0] == '\n' || tmp[loop] == "")
                        continue;
                else OKSites += ({ tmp[loop] });
	return;
}

int is_banned(string site)
{
	string *line;
	int i;

	line = ({});
	line += ({site});
        for (i = 0; i < sizeof(OKSites); i++)
                if (sizeof(regexp(line, OKSites[i])) == 1)
                        return 0;

	for (i = 0; i < sizeof(Sites); i++)
		if (sizeof(regexp(line, Sites[i])) == 1)
		{
			log_file("ATTEMPT_LOGIN",sprintf("SOMEONE  tried to login from banned site: %s\n",site));
			return 1;
		}
	return 0;
}	

void print()
{
	int i;
	write("BANNED:\n");
	for (i = 0; i < sizeof(Sites); i++)
		write(Sites[i] + "\n");
	write("ALLOWED:\n");
        for (i = 0; i < sizeof(OKSites); i++)
                write(OKSites[i] + "\n");
}

void add(string site)
{
	int i;
	
	Sites += ({site});
	write_file(BANNED_SITES, Sites[sizeof(Sites)-1] + "\n", 0);
	write("�ϣ��ˣ�\n");

}

void delete(string site)
{
        int i;

        OKSites += ({site});
        write_file(ALLOWED_SITES, OKSites[sizeof(OKSites)-1] + "\n", 0);
        write("�ϣ��ˣ�\n");


}

void dynamic_add(string site)
{
	Sites += ({site});

}

void dynamic_remove(string site)
{
	OKSites += ({site});

}
