inherit NPC;

void create()
{
        set_name("��³����Ů", ({ "pretty girl", "girl"}) );
        set("gender", "Ů��" );
        set("age", 17);
        set("long", "����һλ������Ů����С����������³�������ô���ݰף�ɷ�Ǻÿ���\n");

        set("combat_exp", 50000);
        set("attitude", "heroism");
	set("chat_chance" , 15);
	set("chat_msg" , ({ /* sizeof() == 2 */
      		"��³����Ů������������Ŷ����衣\n",
		"��³����Ů�����촽������ʮ��ľ��ķ��\n"
	}) );
        set_skill("unarmed", random(60));
	setup();        
        carry_object(__DIR__"obj/skirt")->wear();
}
