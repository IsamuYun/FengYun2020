// teacher.c

inherit NPC;

void create()
{
	set_name("�λ�", ({ "meng huan", "huan" }) );
        create_family("������", 20, "����");
	set("title", "��������");
        set("vendetta_mark","shaolin");
	set("int",1);
	set("gender", "����" );
	set("age", 57);
        set("chat_chance", 10);
        set("chat_msg", ({
                "�λ��������󽭶�ȥ�����Ծ�ǧ�ŷ��������\n",
        }) );
	set("long",
		"�λ��Ǹ���Ȥ�ĺ��У�������ʱ�����й���ţ�����\n"
		"��Ϊ������;����������Ϊɮ�������Ըѧ����ͷ�\n"
		"�λ����ǻ�̵ģ�\n");
	set("attitude", "peaceful");
	set_skill("literate", 140);
	set_skill("buddhism",100);
	setup();
}

int recognize_apprentice(object ob)
{
	return 1;
}
int accept_object(object who, object ob)
{
  object silk;
  if(ob->query("id") == "tianshus")
{
           command("smile");
           command("say ��λ" + RANK_D->query_respect(who)+ "��лл������һֱ���ҵ��������Ǹ���Ľ�����\n");
silk = new("/questobj/big");
silk->move(who);
tell_object(who,"�λ�����һ��"+silk->query("name")+"��\n");
//silk->move(this_object());
//command("give jin-nang to " + who->query("id"));
who->add("bigtasks",1);
        return 1;
        }
        tell_object(who,"�λ�������ƭ�ң��ⲻ����Ҫ�Ķ�����\n");
        return 0;
}
