// chfn.c

inherit F_CLEAN_UP;
#include <ansi.h>
void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object link;

        if( link = me->query_temp("link_ob") ) {
                write("���� Email address [" + link->query("email") + "]: ");
                input_to("get_email", link);
                return 1;
        }
        return 0;
}
string rp_color(string arg)
{
     if (!arg) return "";
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
        arg = replace_string(arg, "$BNK$", BLINK);
        arg = replace_string(arg, "$NOR$", NOR);
        return arg+NOR;
}

void get_email(string new_email, object link)
{
        if( new_email != "" )
                link->set("email", new_email);

        write("�������ҽ���: (fingerʱ��ʾ)\n");
        link->query_temp("body_ob")->edit((: call_other, __FILE__, "get_profile", link:));
}

void get_profile(object link,string str)
{
        str=rp_color(str);
        link->set("profile", str);
        write("����ǩ����ʽ: (postʱ��)\n");
        link->query_temp("body_ob")->edit((: call_other, __FILE__, "get_signature", link :));
}

void get_signature(object link, string str)
{
        if( strlen(str) > 400 )
                write("ǩ����ʽ̫�����������趨��\n");
        else{
                str=rp_color(str);
                link->set("signature", str);
        }
        write("��ǵ��� save �������������޸ġ�\n");
}

int help(object me)
{
write(@HELP
ָ���ʽ : chfn

��; : �����޸� email address , �༭���ҽ���(finger ʱ����)
       ��ǩ��(post ʱ��)��
HELP
     );
     return 1;
}
