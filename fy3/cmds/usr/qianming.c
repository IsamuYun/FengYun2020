//edit by xgchen@zzfy
//签名指令

#include "ansi.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string *txt;

        if( !arg ) return notify_fail("指令格式：qianming <文字>\n");

        txt = explode(arg, "\n");
        if( (wizardp(me) && sizeof(txt) > 20) || sizeof(txt) > 4 )
                return notify_fail("请将您对自己的签名控制在四行以内。\n");
	
        arg = implode(txt, "\n") + "\n";

        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);
        arg = replace_string(arg, "$BLINK$", BLINK);

        me->set("qianminglong", arg + NOR);
        write("Ok.\n");
        return 1;
}

int help()
{
        write(@TEXT
指令格式：qianming <文字>

这个指令让你设定当你留言的时候能显示你的签名。
签名超过一行时可以使用to qianming。
TEXT
        );
        return 1;
}


