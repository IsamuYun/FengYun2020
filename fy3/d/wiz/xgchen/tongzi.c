#include <ansi.h>
#include <localtime.h>
inherit NPC;
inherit F_VENDOR;
string ask_me();
string ask_zxlw();
string ask_zxlwb();
//string ask_yuandangift();
string ask_zxlwc();
string ask_zxlwd();
string ask_zxlwf();



void create()
{
        set_name(NOR"�˲�ͯ��"NOR, ({ "tongzi" }) );
        set("long",
                "�����������������˲�ͯ�ӡ�\n");
         set("str", 45);
        set("cor", 45);
        set("title", NOR"��������"NOR);
        set("cps", 45);
        set("agi",45);
        set("int",45);
       set("chat_chance", 80);
        set("chat_msg", ({
                "�˲�ͯ�ӵ��������������ˣ�[Ask tongzi about all] \n",
                "��վ��̳��ַΪ[http://club.xilu.com/happyfy3]�� \n",
                                    }) );

       set("attitude","friendly");
                 set("inquiry", ([
                "���ֺ��" : (: ask_me :),
                "��������" : (: ask_zxlw :),
             //    "Ԫ������" : (: ask_yuandangift :),
                "���������ʮ��" : (: ask_zxlwb :),
                "��������һ�ٶ�ʮ��" : (: ask_zxlwc :),
                "��������һ����ʮ��" : (: ask_zxlwd :),
                "��������һ�ٰ�ʮ��" : (: ask_zxlwf :),
             


        ]) );
set("combat_exp", 100000000);
            set("chat_chance", 2);
            set_skill("unarmed", 1000);
            set("force", 10000);
            set("max_kee", 1000000);
            set("kee", 1000000);
        set("force_factor", 1500);
    setup();
}
string ask_me()
{
	object ob;

        if ( (int)this_player()->query("hongbao_over") == 22 )
		return RANK_D->query_respect(this_player()) + 
		"���Ǹ���������?����ռ����ѽ��";
        if ( (int)this_player()->query("hongbao_over") == 1 )
		return RANK_D->query_respect(this_player()) + 
		"�㲻���Ѿ������������?����ռ����ѽ��";
        ob = new("/d/wiz/xgchen/hb.c");
     ob->set("player_id",this_player()->query("id"));
	ob->move(this_player());
        this_player()->set("hongbao_over",22);
            message_vision("$N���һ�������ĺ����\n",this_player());

        return "ϣ����Ŭ����Ϊһ��������������";

}
string ask_zxlw()
{
	object ob;

   
   if ( (int)this_player()->query_skill("idle-force", 1) < 50) 
                return RANK_D->query_respect(this_player()) + 
                "��ķ�����̫����,��Ŭ�����һ�°ɣ�50����80����120����150����180�����в�ͬ��������ȡ��";
   
    if ( (int)this_player()->query("jine_over") == 22 )
		return RANK_D->query_respect(this_player()) + 
		"���Ǹ���������?����ռ����ѽ��";
        if ( (int)this_player()->query("jine_over") == 1 )
		return RANK_D->query_respect(this_player()) + 
		"�㲻�ǵõ��������?����ռ����ѽ��";
        ob = new("/obj/prize/u_goose.c");
     ob->set("player_id",this_player()->query("id"));
	 ob->move(this_player());
        this_player()->set("jine_over",22);
            message_vision("һֻ��������Ľ��ɽ�$N����,��Ȼ�����ˡ�\n",this_player());

        return HIY"һֻ��������Ľ��!�����Դ�������!�����˳���Ϸ�󽫲�������!"NOR;

}

string ask_zxlwb()
{
	object ob;

   
   if ( (int)this_player()->query_skill("idle-force", 1) < 80) 
                return RANK_D->query_respect(this_player()) + 
                "��ķ�����̫����,��Ŭ�����һ�°ɣ�50����80����120����150����180�����в�ͬ��������ȡ��";
   
    if ( (int)this_player()->query("jineb_over") == 80 )
		return RANK_D->query_respect(this_player()) + 
		"���Ǹ����������?����ռ����ѽ��";
        if ( (int)this_player()->query("jineb_over") == 1 )
		return RANK_D->query_respect(this_player()) + 
		"�㲻�ǵõ���������?����ռ����ѽ��";
        ob = new("/obj/prize/fenghuang.c");
     ob->set("player_id",this_player()->query("id"));
	 ob->move(this_player());
        this_player()->set("jineb_over",80);
            message_vision("һֻ��������Ľ��˷ɽ�$N����,��Ȼ�����ˡ�\n",this_player());

        return HIY"һֻ��������Ľ���!�����Դ�������!�����˳���Ϸ�󽫲�������!"NOR;

}

string ask_zxlwc()
{
	object ob;

   
   if ( (int)this_player()->query_skill("idle-force", 1) < 120) 
                return RANK_D->query_respect(this_player()) + 
                "��ķ�����̫����,��Ŭ�����һ�°ɣ�50����80����120����150����180�����в�ͬ��������ȡ��";
   
    if ( (int)this_player()->query("jinec_over") == 33 )
		return RANK_D->query_respect(this_player()) + 
		"���Ǹ������������?����ռ����ѽ��";
        if ( (int)this_player()->query("jinec_over") == 1 )
		return RANK_D->query_respect(this_player()) + 
		"�㲻�ǵõ�����������?����ռ����ѽ��";
        ob = new("/obj/prize/qilin.c");
     ob->set("player_id",this_player()->query("id"));
	 ob->move(this_player());
        this_player()->set("jinec_over",33);
            message_vision("һֻ��������Ľ�����ɽ�$N����,��Ȼ�����ˡ�\n",this_player());

        return HIY"һֻ��������Ľ�����!�����Դ�������!�����˳���Ϸ�󽫲�������!"NOR;

}


string ask_zxlwd()
{
	object ob;

   
   if ( (int)this_player()->query_skill("idle-force", 1) < 150) 
                return RANK_D->query_respect(this_player()) + 
                "��ķ�����̫����,��Ŭ�����һ�°ɣ�50����80����120����150����180�����в�ͬ��������ȡ��";
   
    if ( (int)this_player()->query("jined_over") == 15 )
		return RANK_D->query_respect(this_player()) + 
		"���Ǹ����������?����ռ����ѽ��";
        if ( (int)this_player()->query("jined_over") == 15 )
		return RANK_D->query_respect(this_player()) + 
		"�㲻�ǵõ���������?����ռ����ѽ��";
        ob = new("/obj/prize/jinpeng.c");
     ob->set("player_id",this_player()->query("id"));
	 ob->move(this_player());
        this_player()->set("jined_over",15);
            message_vision("һֻ��������Ľ����ɽ�$N����,��Ȼ�����ˡ�\n",this_player());

        return HIY"һֻ��������Ľ��������Դ�������!�����˳���Ϸ�󽫲�������!"NOR;

}


string ask_zxlwf()
{
	object ob;

   
   if ( (int)this_player()->query_skill("idle-force", 1) < 180) 
                return RANK_D->query_respect(this_player()) + 
                "��ķ�����̫����,��Ŭ�����һ�°ɣ�50����80����120����150����180�����в�ͬ��������ȡ��";
   
    if ( (int)this_player()->query("jinef_over") == 18 )
		return RANK_D->query_respect(this_player()) + 
		"���Ǹ����������?����ռ����ѽ��";
        if ( (int)this_player()->query("jinef_over") == 18 )
		return RANK_D->query_respect(this_player()) + 
		"�㲻�ǵõ���������?����ռ����ѽ��";
        ob = new("/obj/prize/dragon.c");
     ob->set("player_id",this_player()->query("id"));
	 ob->move(this_player());
        this_player()->set("jinef_over",18);
            message_vision("һֻ��������Ľ����ɽ�$N����,��Ȼ�����ˡ�\n",this_player());

        return HIY"һֻ��������Ľ��������Դ�������!�����˳���Ϸ�󽫲�������!"NOR;

}
/*
string ask_yuandangift()
{
        string e_time, week, month, year;
        string c_week, c_year, c_month, c_time;
        int day, hour, minute, second;
        object gift;
        string *month_name = ({"Jan","Feb","Mar","Apr","May","Jun","Jul",
                "Aug","Sep","Oct","Nov","Dec"});
        string *week_name = ({"Mon","Tue","Wed","Thu","Fri","Sat","Sun"});
        if(this_player()->query("yuandangift")>2007)
                   return "����ô��ô̰�İ���\n";
        if ( stringp((string)localtime(time()) ) )
                e_time = (string)localtime(time());
        else e_time = ctime(time());
        sscanf(e_time,"%s %s %d %d:%d:%d %s", week, month, day, hour, minute, second, year);
        c_month = chinese_number(member_array(month, month_name) + 1);
        if(c_month+"��"+chinese_number(day) != "һ��һ")
                    return "������"+c_month+"��"+chinese_number(day)+"�գ����ǽڼ��գ�����û�����﷢�š�\n";

        this_player()->set("yuandangift",2008);
        gift = new("/d/wiz/tiandi/obj/hongbao");
        gift->move(this_player());
        message_vision("$N����$n˵����лл��֧�ֱ�վ��ף��Ԫ�����֡�˵��Ӱ����ó�һ�����������$n��\n",this_object(),this_player());
        return "����Ԫ��������˻����Ƕడ��\n";
}
*/

