// mailbox.c
// �޸ģ���ɽ��ѧ  �����ᣨMicro��----Micro_Liang@Hotmail.Com

#include <ansi.h>

inherit ITEM;
inherit F_SAVE;

mapping *mails;

void get_mail_text(mapping mail, string str);

void create()
{
        set_name("����", ({ "mailbox", "box" }) );
        set_weight(400);
        set("no_put", 1);
        set("no_get", 1);
        set("no_drop", 1);
        set("long", @LONG
����һ���������š����ŵ����䣬�����������ָ������������ʼ���
[36m
send    <ĳ��>            ���Ÿ�����
forward <�ż����> <ĳ��> ��ĳ����ת�ı���
check                     �鿴�����е��ż�
read    <�ż����>        �Ķ�һ���ż�
discard <�ż����>        ����һ���ż�
[2;37;0m
LONG
        );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "wood");
        }
}

int set_owner(string id)
{
        set("owner_id", id);
        return restore();
}

void init()
{
        object ob;

        if( this_player() && environment() == this_player() ) {

                set_owner( (string)this_player()->query("id") );
                this_player()->set_temp("mbox_ob", this_object());
                set_name( this_player()->name(1) + "������", ({ "mailbox", "box" }) );

                add_action("do_mail", "send");  add_action("do_mail", "mail");
                add_action("do_forward", "forward");
                add_action("do_from", "check"); add_action("do_from", "from");
                add_action("do_read", "read");
                add_action("do_discard", "discard");

                if( !pointerp(mails) || !sizeof(mails) ) return;
                write(HIY "\n������������ڹ���" + CHINESE_D->chinese_number(sizeof(mails)) + "���ż���\n" NOR);
        }
}

string query_save_file()
{
        string id;

        if( !stringp(id = query("owner_id")) ) return 0;

        return DATA_DIR + "mail/" + id[0..0] + "/" + id;
}

void receive_mail(mapping mail)
{
        if( !pointerp(mails) ) mails = ({ mail });
        else mails += ({ mail });
        save();
}

void send_mail(string rcvr, mapping mail)
{
        object ppl, ob, mbx;
        object user, userb;
        // Acquire the login object of receiver and mark the arrival of newmail.
        ob = FINGER_D->acquire_login_ob(rcvr);
        if( !ob ) {
                write("û������˴��ڡ�\n");
                return;
        }
        ob->set("new_mail", 1); 
        ob->save();

        // Get the mailbox or make a new one if not found.
        ppl = find_player(rcvr);
        if(ppl) mbx = ppl->query_temp("mbox_ob");
        if( !mbx ) {
                mbx = new(MAILBOX_OB);
                mbx->set_owner(rcvr);
        }

        // Receive the mail and destruct the objects if receiver is off-line.
        mbx->receive_mail(mail);
        if(!ppl) {
                destruct(mbx);
                destruct(ob);
        }
}

int do_mail(string arg)
{
        mapping mail;

        if( this_player()!=environment() ) return 0;

        if( !arg || arg=="" )
                return notify_fail("��Ҫ���Ÿ�˭��\n");

        mail = ([
                "from": this_player()->name(1) + "(" + this_player()->query("id") + ")",
                "title": "����",
                "to": arg,
                "time": time(),
                "text": ""
        ]);
        write("�ż����⣺");
        input_to("get_mail_title", mail);
        return 1;
}

void get_mail_title(string str, mapping mail)
{
        if( str!="" ) mail["title"] = str;
        write("�ż����ݣ�\n");
        this_player()->edit( (: get_mail_text, mail :) );
}

void get_mail_text(mapping mail, string str)
{
        mail["text"] = str;
        write("���Լ�Ҫ��һ�ݱ�����(y/n)��[n]");
        input_to("confirm_copy", mail);
}

void confirm_copy(string yn, mapping mail)
{
        if( yn[0]=='y' || yn[0]=='Y' ) receive_mail(mail);
        send_mail(mail["to"], mail);
        write("Ok.\n");
}

int query_mails()
{
        return sizeof(mails);
}

int do_from()
{
        int i;

        if( !pointerp(mails) || !sizeof(mails) ) {
                write("���������Ŀǰû���κ��ż���\n");
                return 1;
        }
        write("������������ڹ��� " + sizeof(mails) + " ���ż���\n\n");
        for(i=0; i<sizeof(mails); i++)
                printf("%2d %-50s �����ˣ�%-20s\n",
                        i+1, mails[i]["title"], mails[i]["from"] );
        write("\n");
        if(this_player()->query("mails") != sizeof(mails)){
            this_player()->set("mails", sizeof(mails));
            this_player()->save();
        }
        return 1;
}

int do_read(string arg)
{
        int num;

        if( !arg || !sscanf(arg, "%d", num) )
                return notify_fail("��Ҫ����һ���ţ�\n");

        if( !pointerp(mails) || num < 1 || num > sizeof(mails) )
                return notify_fail("û�������ŵ��ż���\n");

        num --;

        printf("�ż����⣺%s\n�� �� �ˣ�%s\n\n%s\n",
                mails[num]["title"], mails[num]["from"], mails[num]["text"] );

        return 1;
}

int do_discard(string arg)
{
        int num;

        if( !arg || !sscanf(arg, "%d", num) )
                return notify_fail("��Ҫ������һ���ţ�\n");

        if( !pointerp(mails) || num > sizeof(mails) )
                return notify_fail("û�������ŵ��ż���\n");

        num --;

        if(sizeof(mails) == 1){
            mails = 0;
            write("����������.\n");
        } else if(num == 0) {
            mails = mails[num+1..sizeof(mails)-1];
        } else {
            mails = mails[0..num-1] + mails[num+1..sizeof(mails)-1];
        }
        write("Ok.\n");
        save();
        if(this_player()->query("mails") != sizeof(mails)){
            this_player()->set("mails", sizeof(mails));
            this_player()->save();
        }
        return 1;
}

int do_forward(string arg)
{
        string dest;
        int num;
        mapping m;

        if( !arg || sscanf(arg, "%d %s", num, dest)!=2 )
                return notify_fail("��Ҫ����һ����ת�ĸ����ˣ�\n");

        if( !pointerp(mails) || num > sizeof(mails) )
                return notify_fail("û�������ŵ��ż���\n");

        num --;

        m = ([]);
        m["title"] = mails[num]["title"];
        m["text"] = mails[num]["text"];
        m["time"] = mails[num]["time"];
        m["from"] = mails[num]["from"] + "/ת����" + this_player()->query("name");
        m["to"] = dest;
        send_mail( dest, m );
        write("Ok.\n");

        return 1;
}

void owner_is_killed() { destruct(this_object()); }
