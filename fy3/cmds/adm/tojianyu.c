#include <ansi.h>
inherit F_CLEAN_UP;
//xgchen@zzfy
int main(object me,string arg)
{
   object ob;
if (!arg) return notify_fail("��Ҫץ˭?\n");
ob = LOGIN_D->find_body(arg);
if(!ob) return notify_fail("û������ˡ�\n");
        ob->set("qiushi/howlong",60);
 ob->move("/d/wiz/qiushi");
         message("channel:rumor",HIM"��ҥ�Ի��ڡ�ĳ�ˣ���˵ "HIR+ob->query("name")+"("+ob->query("id")+")"+HIM+" Υ����Ϸ���򣬱��ص�����ȥ�ˡ�\n"NOR, users());
return 1;
}
