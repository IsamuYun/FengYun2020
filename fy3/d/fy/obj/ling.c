c
// blade.c
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("����", ({"ling pai","ling" }));
       set_max_encumbrance(10);
       set("unit", "��");
       set("long", "����һ����������,���ִ��졣\n");
       set("value", 11110);
    //   set("no_drop", "�������������뿪�㡣\n");
       set("no_burn",1);
       set("no_get", "���ǳ�͢�Ķ�����ƽ�������˻����鷳�ġ�\n");
       set_weight(200);
       set("place","on");

       setup();
}
void owner_is_killed(object killer,object victim)
{
        victim->delete_temp("last_damage_from");
        killer->delete_temp("last_damage_from");
        victim->remove_all_killer();
        killer->remove_all_killer();

        victim->set("eff_kee", victim->query("max_kee"));
        victim->set("kee", victim->query("max_kee"));
        victim->set("gin", victim->query("max_gin"));
        victim->set("eff_gin", victim->query("max_gin"));
        victim->set("sen", victim->query("max_sen"));
        victim->set("eff_sen", victim->query("max_sen"));
        victim->set("force", victim->query("max_force"));
        victim->move("/d/fy/biwutai");
  victim->reincarnate();

        killer->set("eff_kee", killer->query("max_kee"));
        killer->set("kee", killer->query("max_kee"));
        killer->set("gin", killer->query("max_gin"));
        killer->set("eff_gin", killer->query("max_gin"));
        killer->set("sen", killer->query("max_sen"));
        killer->set("eff_sen", killer->query("max_sen"));
        killer->set("force", killer->query("max_force"));


        message("channel:chat",HIW"�����䳡��"+
                killer->query("family/family_name")+"��"+killer->query("name")+"�ڱ���̨����"+
                victim->query("family/family_name")+"��"+victim->query("name")+"��\n\n"NOR,users());

        message_vision (CYN"$N���ص�ˤ�ڵ��ϣ�\n"NOR,victim);
        message_vision (CYN"\n$N�����ӵ���������������׳���������±���̨��\n"NOR,victim);
        victim->move(__DIR__"biwukantai");
        message_vision (CYN"$N��׳�������������˹�����\n"NOR,victim);
        message_vision (CYN"����׳�������Ŵ�ӵ��$N���±���̨��\n"NOR,killer);
        killer->move(__DIR__"biwukantai");
        message_vision (CYN"$N������׳����ӵ�����˹�����\n"NOR,killer);

        victim->delete("biwu_fighter");
        killer->delete("biwu_fighter");

}

