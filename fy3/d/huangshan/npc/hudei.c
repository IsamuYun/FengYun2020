
inherit NPC;

void create()
{
        set_name("������", ({ "hudie" }) );
//	set("title", HIY "��"+ HIR "��" +  HIC"��" NOR);
        set("race", "Ұ��");
        set("age", 1);
        set("long", "һ������ɫ�������ĺ���\n");
        set("max_kee", 1);
        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" }) );
         set("chat_chance", 3);
       set("chat_msg", ({
                "�����ĺ�����������ļ�ͷ��\n",
                "��ɫ�ĺ����ɹ�����ǰ��\n",
		  "��ɫ�ĺ��������ˡ�\n",
        }) );

        set_skill("dodge", 200);

        setup();
}

