// logind.c
// �޸���2001 by xgchne@zzfy
#define VISITORS "/data/mud/MUDVISITOR"
#include <ansi.h>
#include <command.h>
#include <login.h>

inherit F_DBASE;
int wiz_lock_level = WIZ_LOCK_LEVEL;
int new_user_lock = NEW_USER_LOCK;
string L_IP = "192.0.5.72";
string Rname;
string *banned_name = ({
        "��", "��", "��", "��", "��", "��", "��",
        "����","����", "���ƣɣ�","���Ƣ�", "����",
        "����",  "����","�ɹ���","���ƣɣɣ�","���Ƣ�",
        "ϵͳ", "��ǻ�",  "���־",  "����", "ϵͳ����","��������","����",
});
string *banned_id= ({
        "chat", "new", "fy", "rumor", "tell", "none", "reboot",
        "shutdown","core", "fymud","mud", "fuck","reply","set",
        "dick",  "shit","cao","cunt","slut",
});

// those start location will be changed according to national
// ���� ���� �����磬�������ɹţ���������
string *start_loc = ({
        "/d/fy/fqkhotel",
        "/d/chenxiang/cxcenter",
        "/u/guanwai/inn",
        "/d/laowu/inn",


});

string *national = 
({
        "����",
        "����",
        "����",
        "�ɹ���",


});

private void get_id(string arg, object ob);
private void read_msg(string arg, object ob);
private void get_resp(string arg, object ob);
private void confirm_id(string yn, object ob);
object make_body(object ob);
private init_new_player(object user);
varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
object find_body(string name);
int check_legal_id(string arg);
int howmany_user();
int howmany_visitor();
int check_legal_name(string arg);
int check_legal_password(object ob,string arg);
int set_attribute(object user,int tol, int fle, int agi, int dur, int intt, int str, int con, int spi, int per, int cor, int cps, int kar);
int cphirdir(string dirstr, string newdirstr);
string random_name();
void set_visitor(int num);
void create() 
{
        seteuid(getuid());
        set("channel_id", "���߾���");
}
void logon(object ob)
{
        object *usr;
        string *dir,*ppls;
        int i, wiz_cnt,ppl_cnt,ppl1_cnt,login_cnt;
          int user_num;
    int iplimit;
// Before we do all this, see if this installation is legal
//	if(SECURITY_D->check_illegal(L_IP))
//	shutdown(0);
	if (BAN_D->is_banned(query_ip_name(ob))  ||
	    BAN_D->is_banned(query_ip_number(ob))) {
                write("�Բ���������������ߣ����ǻᾡ�������ϵ��\n");
		destruct(ob);
                return ;
        }

   switch ( random(6))
    {
   case 0:
   cat(WELCOME);
   break;
   case 1:
   cat("/adm/etc/welcome2");
    break;
    case 2:
   cat("/adm/etc/welcome3");
   break;
   case 3:
   cat("/adm/etc/welcome4");
   break;
   case 4:
   cat("/adm/etc/welcome5");
    break;
    case 5:
   cat("/adm/etc/welcome6");
   break;
   }
        UPTIME_CMD->main();
        CT_CMD->main();
        usr = users();
       user_num=howmany_visitor();
       set_visitor(user_num+1);
        wiz_cnt = 0;
        ppl_cnt = 0;
        ppl1_cnt = 0;
        login_cnt = 0;
        iplimit = 0;
         dir = get_dir(DATA_DIR + "login/");
        for(i=0; i<sizeof(dir); i++) {
                reset_eval_cost();
                ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
                ppl1_cnt += sizeof(ppls);
        }
        for(i=0; i<sizeof(usr); i++) {
                            if( query_ip_name(usr[i])==query_ip_name(ob)) iplimit ++;
                if( !environment(usr[i]) ) login_cnt++;
                else if( wizardp(usr[i]) ) wiz_cnt++;
                else ppl_cnt++;
        }
 if (iplimit>20)
        {
		write("�Բ���" + MUD_NAME + "������ͬip���ص�¼��\n");
		destruct(ob);
		return;
        }
               printf(HIR"һ�����ƹ���"NOR+HIC"%s"+NOR+HIR"�����ע���˵�����\n"NOR,chinese_number(ppl1_cnt) );
       printf(HIR"һ������Ŀǰ����"+NOR+HIC+"%s"+NOR+HIR+"λ�����Ϸ�С���"+NOR+HIC+"%s"+NOR+HIR+"λ���������ߡ�\n"NOR,
    chinese_number(ppl_cnt+login_cnt), chinese_number(login_cnt));
       write("����Ӣ�����֣�");
        input_to( (: get_id :), ob );
}
void set_visitor(int num)
{
	if(num>0)
		write_file(VISITORS, sprintf("VISITORS %d", num), 1);
	else
		write("��ʦ��ע���������Ŀ����!\n");
	return;
}
int howmany_visitor()
{
	int num=0;
	string content, format;
	content=read_file(VISITORS);
	sscanf(content, "%s %d", format, num);
	if(format!="VISITORS")
		write(format+"\n��ʦ��ע���������Ŀ����!\n");
	return num;
}
private void get_id(string arg, object ob)
{
        object ppl;


        arg = lower_case(arg);
        if( !check_legal_id(arg)) {
                write("����Ӣ�����֣�");
                input_to("get_id", ob);
                return;
        }
#ifdef MAX_USERS
        if( (string)SECURITY_D->get_status(arg)=="(player)"
        && sizeof(users()) >= MAX_USERS ) {
                ppl = find_body(arg);
        // Only allow reconnect an interactive player when MAX_USERS exceeded.
                if( !ppl || !interactive(ppl) ) {
                        write("�Բ���" + MUD_NAME + 
"��ʹ�����Ѿ�̫���ˣ������������\n");
                        destruct(ob);
                        return;
                }
        }
#endif

       if( wiz_level(arg) < wiz_lock_level ) {
                write("�Բ���" + MUD_NAME + 
"Ŀǰ����ά��֮�У����Ժ������ߡ�\n");
              destruct(ob);
                return;
      }
        
        if( (string)ob->set("id", arg) != arg ) {
                write("Failed setting user name.\n");
                destruct(ob);
                return;
        }
// toomany guets nowdays
        if( arg=="guesttttttttt" ) {
                // If guest, let them create the character.
                confirm_id("Yes", ob);
                return;
        } else if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 
) {
                if( ob->restore() ) {
                        write("��Ӣ�������ѱ�ʹ�ã���������ʺŵ����룺");
                        input_to("get_passwd", 1, ob);
                        return;
                }
                write("�������ﴢ�浲����һЩ���⣬������ guest 
����֪ͨ��ʦ����\n");
                destruct(ob);
                return;
        }
        if(new_user_lock) {
        write("����һ�����Ʋ������µ�������Ժ��ٴ����µ����\n");
	destruct(ob);
	return;
	}
        write("ʹ�� " + (string)ob->query("id") + " 
������ֽ��ᴴ��һ���µ������ȷ����(y/n)��");
        input_to("confirm_id", ob);
}

private void get_passwd(string pass, object ob)
{
        string my_pass;
        object user;

        write("\n");
        my_pass = ob->query("password");
        if( crypt(pass, my_pass) != my_pass ) {
                write("�������\n");
		log_file("ATTEMPT_LOGIN",sprintf("FAILED: %s tried to login from %s\n",
		ob->query("id"), query_ip_name(ob)));
                destruct(ob);
                return;
        }

        // Check if we are already playing.
        user = find_body(ob->query("id"));
        if (user) {
                if( user->query_temp("netdead") ) {
                        reconnect(ob, user);
                        return;
                }
                
write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)");
                input_to("confirm_relogin", ob, user);
                return;
        }

        if( objectp(user = make_body(ob)) ) {
                if( user->restore() ) {
                        log_file( "USAGE", sprintf("%s loggined from %s (%s)\n", user->query("id"),
                                query_ip_name(ob), ctime(time()) ) );
			log_file("STAT", sprintf("ON %s %s %d %d %d %d %d %d %s\n",
user->query("id"),user->query("name"),user->query("combat_exp"),
user->query("deposit"),user->query("potential"),user->query("TASK"),
user->query("mud_age"), user->query("QUEST"), ctime(time()) ) );
			if(time()-(int)user->query("kickout_time") < 3600)
			{
			write("������û�н�����Ƶ�Ȩ������һСʱ�������ߡ�\n");
			destruct(user);
			destruct(ob);
			return;
                          }
                       if(time()-(int)user->query("quit_time") < 5)
                        {
                        write(HIR"\n����˳���Ϸ"+ chinese_number(time()-(int)user->query("quit_time"))+"�룬Ϊ�˼���ϵͳ����������������룬лл������^0^\n\n");
                        destruct(user);
                        destruct(ob);
                        return;
                }

                        enter_world(ob, user);
                        return;
                } else {
                        destruct(user);
                }
        }
        write("�������´���������\n");
        confirm_id("y", ob);
}

private void confirm_relogin(string yn, object ob, object user)
{
        object old_link;

        if( yn=="" ) {
                
write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)");
                input_to("confirm_relogin", ob, user);
                return;
        }       

        if( yn[0]!='y' && yn[0]!='Y' ) {
                write("�ðɣ���ӭ�´�������\n");
                destruct(ob);
                return;
        } else {
                tell_object(user, "���˴ӱ�( " + query_ip_name(ob)
                        + " )����ȡ���������Ƶ����\n");
                log_file( "USAGE", sprintf("%s replaced by %s (%s)\n", 
user->query("name"),
                        query_ip_name(ob), ctime(time()) ) );
        }

        // Kick out tho old player.
        old_link = user->query_temp("link_ob");
        if( old_link ) {
                exec(old_link, user);
                destruct(old_link);
        }

        reconnect(ob, user);    
}

private void confirm_id(string yn, object ob)
{
        if( yn=="" ) {
                write("ʹ��������ֽ��ᴴ��һ���µ������ȷ����(y/n)��");
                input_to("confirm_id", ob);
                return;
        }       

        if( yn[0]!='y' && yn[0]!='Y' ) {
                write("�ðɣ�������������������Ӣ�����֣�");
                input_to("get_id", ob);
                return;
        }

        write( @TEXT
[35m
һ��������һ���Թ���С˵Ϊ�����������Ϸ��������
һ�������ʣ��и��ԣ��ֲ���̫��ֵ��������֣��ر�
Ҫ���������ǣ�����ʹ�ù���С˵�е��������������
�������������������Ὣ�����ٸ��ģ���������ء�
[37m
[31m
����������������������֣���ֱ���ûس����ۣңţԣգңΣݡ�
[37m
TEXT
        );
        write("�����������֣�");
        input_to("get_name", ob);
}
private void read_msg(string arg, object ob)
{
        write(HIY "\n���ڹ���"+HIR+"/cmds/imm/checkip"->tot_usr(ob)+HIY+"λ��Ҵ����վ�㣨"+
query_ip_name(ob)+"�����ߡ�\n\n"+NOR);
        return;
}
private void get_resp(string arg, object ob)
{
        if( arg=="" ) {
                write("������(y)������(n)����������֣�");
                input_to("get_resp", ob);
                return;
        }

        if( arg[0]=='y' || arg[0]=='Y' )
	{
        printf("%O\n", ob);
        ob->set("name", Rname);
        write("���趨�������룺");
        input_to("new_password", 1, ob);
	return;
	}
        else 
	if( arg[0]=='n' || arg[0]=='N')
	{
	Rname = random_name();
        write("������(y)������(n)����������֣�");
        printf( HIY" -- %s ��"NOR, Rname);
        input_to("get_resp", ob);
	return;
	}
        else {
                write("�Բ�����ֻ��ѡ������(y)������(n)�� ");
                input_to("get_resp", ob);
                return;
        }


}

private void get_name(string arg, object ob)
{
	string name;
        if( arg =="")
        {
	Rname = random_name();
        write("������Ҫ������������������֣���\n");
        write("������(y)������(n)����������֣�");
        printf( HIY" -- %s ��"NOR, Rname);
        input_to("get_resp", ob);
	}
	else {
        if( !check_legal_name(arg) ) {
                write("�����������֣�");
                input_to("get_name", ob);
                return;
        }

        printf("%O\n", ob);
        ob->set("name", arg);
        write("���趨�������룺");
        input_to("new_password", 1, ob);
		}
}

private void new_password(string pass, object ob)
{
        write("\n");
        if( !check_legal_password(ob,pass)) {
                input_to("new_password", 1, ob);
	write("���趨�������룺");
                return;
        }
        ob->set("password", crypt(pass,0) );
        write("��������һ���������룬��ȷ����û�Ǵ�");
        input_to("confirm_password", 1, ob);
}

private void confirm_password(string pass, object ob)
{
        string old_pass;
        write("\n");
        old_pass = ob->query("password");
        if( crypt(pass, old_pass)!=old_pass ) {
                write("��������������벢��һ�����������趨һ�����룺");
                input_to("new_password", 1, ob);
                return;
        }

        write("���ĵ����ʼ���ַ��");
        input_to("get_email",  ob);
}

private void get_email(string email, object ob)
{
        object user;

        ob->set("email", email);

  // If you want do race stuff, ask player to choose one here, then you can
  // set the user's body after the question is answered. The following are
        // options for player's body, so we clone a body here.
        ob->set("body", USER_OB);
// ��ֹͬ��id�Ķ��ص�½��write by tmpa 2002.1
        user = find_body(ob->query("id"));
         if (user) {
           write("����һ���˸ո�ע�������id�������ǻ�һ����\n\n");
           destruct(ob);
           return;
         }

        if( !objectp(user = make_body(ob)) )
                return;

        write("��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
        input_to("get_gender", ob, user);
}

private void get_gender(string gender, object ob, object user)
{
        if( gender=="" ) {
                write("��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
                input_to("get_gender", ob, user);
                return;
        }

        if( gender[0]=='m' || gender[0]=='M' )
                user->set("gender", "����");
        else if( gender[0]=='f' || gender[0]=='F' )
                user->set("gender", "Ů��" );
        else {
                write("�Բ�����ֻ��ѡ������(m)��Ů��(f)�Ľ�ɫ��");
                input_to("get_gender", ob, user);
                return;
        }
	write("
		��������
		��������
		��������
		�����ɹ���
		\n");
	write("��ѡ�����ڷ��Ƣ��е����壨0��1��2��3����");
	input_to("get_nresp",ob, user);
}
private void get_nresp(string arg, object ob, object user)
{
        if( arg=="" ) {
                write("��ѡ������һ�������е����壨0��1��2��3����");
                input_to("get_nresp", ob, user);
                return;
        }
        if( arg[0]=='0' || arg[0]=='1' || arg[0]=='2'|| arg[0]=='3')
        {
        log_file( "USAGE", sprintf("%s was created from %s (%s)\n", 
user->query("id"),
                query_ip_name(ob), ctime(time()) ) );
	user->set("national",national[(int) (arg[0]-'0')]);
        init_new_player(user);
        enter_world(ob, user);
	return;
	}
        else {
                write("�Բ�����ֻ�ܴӣ�0,1,2,3����ѡ�� ");
                input_to("get_nresp", ob,user);
                return;
        }

}

object make_body(object ob)
{
        string err;
        object user;
        int n;

        user = new(ob->query("body"));
        if(!user) {
                
write("���ڿ������������޸�ʹ��������ĳ�ʽ���޷����и��ơ�\n");
                write(err+"\n");
                return 0;
        }
        seteuid(ob->query("id"));
        export_uid(user);
        export_uid(ob);
        seteuid(getuid());
        user->set("id", ob->query("id"));
        user->set_name( ob->query("name"), ({ ob->query("id")}) );
        return user;
}

private init_new_player(object user)
{
	string national;
        user->set("title", "��ͨ����");
        user->set("birthday", time() );
        user->set("potential", 20099);
	national = user->query("national");
	switch(national){
		case "����":
// ���� high int, high per, low cor, low tol
		set_attribute(user,5,10,10,10,12,10,10,10,20,5,10,10);     
			break;
	        case "����":
//���� high agi, high kar, low con, low spi
                set_attribute(user,10,10,20,10,10,10,5,5,10,10,10,20);
                        break;
         	case "����":
//���� high cps, spi, low int,dur
                set_attribute(user,10,10,10,5,8,10,10,20,10,10,20,10);
                        break;
         	case "�ɹ���":
//�ɹ��� high str, fle , low agi, dur
		set_attribute(user,10,20,5,5,10,20,10,10,10,10,10,10);
                        break;
			}	

	user->setup();
        user->set("food", user->max_food_capacity());
        user->set("water", user->max_water_capacity());
	user->set("env/wimpy", 50);
	user->set("combat_exp",100000);
       user->set_skill("unarmed",50);
       user->set_skill("parry",50);
       user->set_skill("dodge",50);
     user->set_skill("literate",48);
     user->set_skill("force",48);

        user->set("channels", ({ "chat","fy","new","rumor" }) );
}

varargs void enter_world(object ob, object user, int silent)
{
     object cloth, room,obj,*inv;
     string startroom;
	mixed info;
	string id;
	string mailfile;
	int laston;
        user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);
        exec(user, ob);

        write(CLR + "ĿǰȨ�ޣ�" + wizhood(user) + "\n");
        user->setup();

        // In case of new player, we save them here right aftre setup 
        // compeleted.
        user->save();
        ob->save();

        cloth = new("/obj/cloth");
        cloth->move(user);
        cloth->wear();
        if( !silent ) {
                cat(MOTD);
	id = user->query("id");
	mailfile = DATA_DIR+ "mail/" + sprintf("%c",id[0]) + "/" + id + ".o";
	if( file_size(mailfile) > 0 )
	info = stat(mailfile);
	if( info )
	if((int) info[0] >=0 ) {
		laston = (int) ob->query("last_on");
	if( laston < info[1])                        write( HIY +
"\n�������ţ��뵽���Ƴ���վ��һ�ˣ���\n\n" + NOR);
                }
	write( HIR+"�ϴ����ߵ�ַ��" + ob->query("last_from") + "��"+
		ctime(ob->query("last_on")) + "��\n\n" + NOR);
	        write("���ûس����ۣңţԣգңΣݣ���������");
	        input_to( "read_msg", user );
                if( user->is_ghost() )
                        startroom = DEATH_ROOM;
                else if( !stringp(startroom = user->query("startroom")) )
		{
        switch((string) user->query("national")){
                case "����":
			startroom = start_loc[0];
                        break;
                case "����":
			startroom = start_loc[1];
                        break;
                case "����":
			startroom = start_loc[3];
                        break;
                case "�ɹ���":
			startroom = start_loc[2];	
                        break;
                        }
		}

                if( !catch(load_object(startroom)) )
		{
                        user->move(startroom);
			user->set("startroom", startroom);
		}
                else {
                        user->move(START_ROOM);
                        startroom = START_ROOM;
                        user->set("startroom", START_ROOM);
                }
                tell_room(startroom, user->query("name") + 
 "���߽���������硣\n",({user}));
                if(file_size("/log/notice")>0){
      write(HIC"\n    �ԡԡԡԡԡԡԡԡԡԡԡ�"HIR"һ����������֪ͨ"NOR HIC"�ԡԡԡԡԡԡԡԡԡԡԡ�\n");
                        write("     "+read_file("/log/notice"));
                        write(HIC"\n    �ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n"NOR);        
}
}
        CHANNEL_D->do_channel( this_object(), "sys",
                sprintf("%s ( %s ) ��%s���߽��롣", user->name(), 
       user->query("id"),query_ip_name(user)) );
		
// user->query("id"),query_ip_name(user)) );
        UPDATE_D->check_user(user);
	STATUS_D->compare_status(user);
        UPGRADE_D->upgrade(user);
       TOPTEN_D->topten_checkplayer(user);
        if( user->query("atman_factor") > user->query_skill("magic")/3 )
        {
                user->set("atman_factor", 0);
        }

        if( user->query("force_factor") > user->query_skill("force")/3 )
        {
                user->set("force_factor", 0);
        }

        if( user->query_skill("essencemagic",1)  > 700 )
        {
                user->set_skill("essencemagic", 200 );
        }

    user->set("env/prompt","");
     
    // add by tiandi to init self weapon
    inv = all_inventory(user);
    if( sizeof(inv) ) {
     //      write ("��Ʒ����"+sizeof(inv)+"\n\n\n");
          obj=first_inventory(user);
       //     write ("�׼���Ʒ����"+obj->query("name")+"\n\n\n");
          	
          while (obj) {
      			if (obj->query("selfmaking"))
                                    {  
             //                           write(obj->query("name")+"�������\n");
           			   obj->restore();
                    }
    				obj = next_inventory(obj);
                       continue;
		   }
	}
}

varargs void reconnect(object ob, object user, int silent)
{
        user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);
        exec(user, ob);

        user->reconnect();
        if( !silent ) {
                tell_room(environment(user), user->query("name") + 
"�������߻ص�������硣\n",
                ({user}));
        }
        CHANNEL_D->do_channel( this_object(), "sys",
                sprintf("%s��%s�������߽��롣", user->query("name"), 
query_ip_name(user)) );
        UPDATE_D->check_user(user);
}

int check_legal_id(string id)
{
        int i;

        i = strlen(id);
        
        if( (strlen(id) < 3) || (strlen(id) > 10 ) ) {
                write("�Բ������Ӣ�����ֱ����� 3 �� 10 ��Ӣ����ĸ��\n");
                return 0;
        }
        while(i--)
                if( id[i]<'a' || id[i]>'z' ) {
                        write("�Բ������Ӣ������ֻ����Ӣ����ĸ��\n");
                        return 0;
                }
        if( member_array(id, banned_id)!=-1 ) {
                write("�Բ�������Ӣ�����ֻ���������˵����š�\n");
                return 0;
	}

        return 1;
}
string random_name()
{
	string *lname = ({
"��","Ǯ","��","��","��","��","֣","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","ʩ","��",
"��","��","��","��","��","κ","��","��","��","л","��","��","��","ˮ","�","��","��","��","��","��","��","��","��","��",
"³","Τ","��","��","��","��","��","��","ɵ","��","Ԭ","��","��","��","ʷ","��","��","��","�","Ѧ","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","ʱ","��","Ƥ","��","��","��","��","��","Ԫ","��","��","ӯ","ƽ","��",
"��","��","Ф","��","Ҧ","��","տ","��","��","ë","��","��","��","��","��","��","��","��","��","��","̸","��","é","��",
"��","��","��","��","��","ף","��","��","��","��","��","��","��","��","֧","��","��","��","¬","Ӣ","��","��","˾��",
"�Ϲ�","ŷ��","�ĺ�","���","����","����","����","�ʸ�","ξ��","����","�̨","����",
"����","���","����","����","̫��","����","����","����","ԯ��","���","����","����",
"����","Ļ��","˾ͽ","ʦ��","��","��ľ","����","����","���","����","����","����",
"��ֺ","�й�","�׸�","����","����","�ַ�","��۳","Ϳ��","��ǧ","����","����","�Ϲ�",
"����","�麣","����","΢��","��","˧","��","��","��","��","��","��","����","����","����","����",
"��","Ĳ","��","��","����","�Ϲ�","ī","��","��","��","��","��","١","��","��","��","��",
			});
			 return (lname[random(sizeof(lname))] + chinese_number(random(20)));
}
int check_legal_name(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 2) || (strlen(name) > 12 ) ) {
                write("�Բ�������������ֱ�����һ�����������֡�\n");
                return 0;
        }
        while(i--) {
                if( name[i]<=' ' ) {
                        write("�Բ�������������ֲ����ÿ�����Ԫ��\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("�Բ��������á����ġ�ȡ���֡�\n");
                        return 0;
                }
        }
        if( member_array(name, banned_name)!=-1 ) {
                write("�Բ����������ֻ���������˵����š�\n");
                return 0;
        }

        return 1;
}
int check_legal_password(object ob,string pass)
{
        int i;
	int bigletter=0;
	int smlletter=0;
	int number=0;
	string id;
        i = strlen(pass);
        if( strlen(pass) <= 5)   {
                write("�Բ����������������������ַ���\n");
                return 0;
        }
	id= ob->query("id");	
	if ( strsrch(id, pass) != -1 || strsrch(pass,id) != -1)
	{
	write("�Բ��������������Ӣ������̫���ˡ�\n");
                return 0;
        }

        while(i--) {
                if( pass[i]<='Z' && pass[i] >='A' ) bigletter++;
		if( pass[i]<='z' && pass[i] >='a' ) smlletter++;

        }
	if( bigletter == 0 || smlletter == 0 || 
	bigletter+smlletter == strlen(pass))
{
        write("����������������д" + HIR"��" + NOR"СдӢ����ĸ"
		+ HIR"��" + NOR"����������ţ����֣���㣩��\n");
	return 0;
}
        return 1;
}

object find_body(string name)
{
        object ob, *body;

        if( objectp(ob = find_player(name)) )
                return ob;
        body = children(USER_OB);
        for(int i=0; i<sizeof(body); i++)
                if( clonep(body[i])
                &&      getuid(body[i]) == name ) return body[i];

        return 0;
}

int set_wizlock(int level)
{
        if( wiz_level(this_player(1)) <= level )
                return 0;
        if( geteuid(previous_object()) != ROOT_UID )
                return 0;
        wiz_lock_level = level;
        return 1;
}
int set_attribute(object user,int tol, int fle, int agi, int dur, int intt, int str, int con, int spi, int per, int cor, int cps, int kar)
{
user->set("tol",tol);
user->set("fle",fle);
user->set("agi",agi);
user->set("dur",dur);
user->set("int",intt);
user->set("str",str);
user->set("con",con);
user->set("spi",spi);
user->set("per",per);
user->set("cor",cor);
user->set("cps",cps);
user->set("kar",kar);
return 1;
}
int cphirdir(string dirstr, string newdirstr)
{
string *dir;
int i;
dir = get_dir(dirstr+"/");
if(!mkdir(newdirstr)) write("FAILED\n");
for(i=0; i<sizeof(dir); i++) {
        if(file_size(dirstr+"/"+dir[i]) == -2 )
                cphirdir(dirstr +"/"+dir[i],newdirstr+"/"+dir[i]);
        cp(dirstr+"/"+dir[i], newdirstr+"/"+dir[i]);
        }
return 1;
}

int set_newuser_lock( int level)
{        new_user_lock = level;
        return level;
}


