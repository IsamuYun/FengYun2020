#include <ansi.h>
inherit F_CLEAN_UP;
//xgchen@zzfy
int main(object me,string arg)
{
   object ob;
if (!arg) return notify_fail("你要抓谁?\n");
ob = LOGIN_D->find_body(arg);
if(!ob) return notify_fail("没有这个人。\n");
        ob->set("qiushi/howlong",60);
 ob->move("/d/wiz/qiushi");
         message("channel:rumor",HIM"【谣言惑众】某人：据说 "HIR+ob->query("name")+"("+ob->query("id")+")"+HIM+" 违反游戏规则，被关到监狱去了。\n"NOR, users());
return 1;
}
