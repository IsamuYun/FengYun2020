// test_npc.c �������NPC����

#define NAME_D    "/cmds/arch/random_name"//�ɶ�Ӧ�����random_name.c�ľ���·��

inherit NPC;

void create()
{
    mapping name;
    name = NAME_D->man_name();
/*���Ҫ����Ů�ԣ���
    name = NAME_D->woman_name();
���Ҫ�����ձ��ˣ���
	name = NAME_D->jap_name();
*/
    set_name(name["name"],({name["id"]}));
	set("gender", "����" );//�Ա��������Ӧ
//���������
   	set("age",30+random(30));
   	set("attitude", "peaceful");
    set("quest_npc",1);

    set("str", 25);
	set("con", 30);
	set("int", 30);
	set("dex", 30);

    set("combat_exp",1000);	
    setup();
}
