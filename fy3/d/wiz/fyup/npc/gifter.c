//by tiandi��ÿ���޸�һ��ʱ�伴�ɣ�Ҳ����������Ķ��壬��������������ǩ��Ҫÿ�μ�1��

#include <ansi.h>
#include <localtime.h>
#define GIFTDATE "ʮ��һ"
#define GIFTREASON "������"
inherit NPC;
inherit F_VENDOR;
string ask_yuandangift();
string ask_when();

void create()
{
        set_name(NOR"����ʹ��"NOR, ({ "gifter" }) );
        set("long",
                "���ǿ��ַ��Ƶ�����ʹ�ߣ�������ڵĶ��ᷢ������Ŷ��\n");
         set("str", 45);
        set("cor", 45);
        set("title", NOR"���ַ���"NOR);
        set("cps", 45);
        set("agi",45);
        set("per",105);
       set("attitude","friendly");
                 set("inquiry", ([
                 "��������" : (: ask_yuandangift :),
	     "����ʱ��" : (: ask_when :),
	  "������ϸ":GIFTDATE+"����"+GIFTREASON+"��",
        ]) );
set("combat_exp", 1);
    setup();
}
string ask_yuandangift()
{
        string e_time, week, month, year;
        string c_week, c_year, c_month, c_time;
        int day, hour, minute, second;
        object gift;
        string *month_name = ({"Jan","Feb","Mar","Apr","May","Jun","Jul",
                "Aug","Sep","Oct","Nov","Dec"});
        string *week_name = ({"Mon","Tue","Wed","Thu","Fri","Sat","Sun"});
	   if(this_player()->query("level") < 10)          // limtied exp >400k
                   return "��ĵȼ�̫�ͣ���ȥ��������ͷ�����ðɣ�\n";

        if(this_player()->query("getgiftno")>4)          // EVERY TIME CHANGE THIS VALUE +1
                   return "����ô��ô̰�İ���\n";
        if ( stringp((string)localtime(time()) ) )
                e_time = (string)localtime(time());
        else e_time = ctime(time());
        sscanf(e_time,"%s %s %d %d:%d:%d %s", week, month, day, hour, minute, second, year);
        c_month = chinese_number(member_array(month, month_name) + 1);
        if(c_month+"��"+chinese_number(day) != GIFTDATE)
                    return "������"+c_month+"��"+chinese_number(day)+"�գ����ǽڼ��գ�����û�����﷢�š�\n";

        this_player()->set("getgiftno",5);        //EVERY TIME ADD 1
        gift = new("/d/wiz/tiandi/obj/hongbao");
        gift->move(this_player());
        gift->set_temp("giftowner",this_player()->query("name"));
//message_vision(gift->query_temp("giftowner")+"\n",this_player());
        message_vision("$N����$n˵����лл��֧�ֱ�վ��ף����տ��֡�˵��Ӱ����ó�һ�����������$n��\n",this_object(),this_player());
        return "���ý���������˻����Ƕడ��\n";
}
string ask_when()
{
	 message_vision("$N����$n˵������һ�η��������ʱ��Ϊ"+GIFTDATE+"�ա�\n",this_object(),this_player());
	 return "�ǵ�����Ŷ���������ӿɾ�û���ˡ�\n";
}
