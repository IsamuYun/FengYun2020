#include <ansi.h>
inherit NPC;
int check_legal_name(string arg);
int check_legal_id(string arg);

void create()
{
        set_name("�콭", ({ "xiaojiang" }) );
        set("gender", "Ů��" );
        set("age", 22);
        set("long","�콭�չˣ���޸�һС������������������Ϳ�ʹÿ�챳һ��С�����������磩����\n");
        set("combat_exp", 5);
        set("chat_chance", 15);
  //      set("chat_msg", ({
  //              (: random_move :)
   //     }) );
        set("attitude", "friendly");
        setup();
        carry_object("/obj/cloth")->wear();

}

void init()
{	
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_yang", "yang");

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "�콭˵������λ" + RANK_D->query_respect(ob)
                                + "��Ҫ��СèС��ô��\n");
                        break;
                case 1:
                        say( "�콭˵������λ" + RANK_D->query_respect(ob)
                                + "����̫�����ˣ��Ҳ������㡣\n");
                        break;
        }
}

int do_yang(string arg)
{
	string ctype, cname, ccolor, cid;
	object ob, me, gold;
	string id,filename;
	object newpet;
        me = this_player();
	id = me->query("id");
        if(!arg || sscanf(arg,"%s %s %s %s",ctype,ccolor,cname,cid ) != 4)
        return notify_fail("ָ���ʽ��yang <type> <color> <name> <english name>\n");
	if(me->is_busy())
	return notify_fail("����һ��������û����ɡ�\n");
	if(file_size( me->query_save_file() + ".pet.o") > 0)
	return notify_fail("���Ѿ�ӵ�����İ��ĳ����ˡ�\n");
	gold = present("gold_money", this_player());
    if(!gold) return notify_fail("������û�н��ӡ�\n");
        if((int) gold->query_amount() < 10000)
        return notify_fail("������û���������ӡ�\n");
	if((int)me->query("score") < 10000)
	return notify_fail("������۲�����\n");
	if( !check_legal_name(cname))
	return notify_fail("");
        if( !check_legal_id(cid))
        return notify_fail("");

	if( ccolor != "$BLK$" && 
	    ccolor != "$NOR$" &&
            ccolor != "$RED$" &&
            ccolor != "$GRN$" &&
            ccolor != "$YEL$" &&
            ccolor != "$BLU$" &&
            ccolor != "$MAG$" &&
            ccolor != "$CYN$" &&
            ccolor != "$WHT$" &&
            ccolor != "$NOR$" &&
            ccolor != "$HIR$" &&
            ccolor != "$HIG$" &&
            ccolor != "$HIY$" &&
            ccolor != "$HIB$" &&
            ccolor != "$HIM$" &&
            ccolor != "$HIC$" &&
            ccolor != "$HIW$" 
	)
	return notify_fail("��֪��Ҫʲô��ɫ��\n");
	cname = ccolor + cname;
        cname = replace_string(cname, "$BLK$", BLK);
        cname = replace_string(cname, "$RED$", RED);
        cname = replace_string(cname, "$GRN$", GRN);
        cname = replace_string(cname, "$YEL$", YEL);
        cname = replace_string(cname, "$BLU$", BLU);
        cname = replace_string(cname, "$MAG$", MAG);
        cname = replace_string(cname, "$CYN$", CYN);
        cname = replace_string(cname, "$WHT$", WHT);
        cname = replace_string(cname, "$HIR$", HIR);
        cname = replace_string(cname, "$HIG$", HIG);
        cname = replace_string(cname, "$HIY$", HIY);
        cname = replace_string(cname, "$HIB$", HIB);
        cname = replace_string(cname, "$HIM$", HIM);
        cname = replace_string(cname, "$HIC$", HIC);
        cname = replace_string(cname, "$HIW$", HIW);
        cname = replace_string(cname, "$NOR$", NOR);
        cname += NOR;
	seteuid(ROOT_UID);
	newpet = new("/obj/pet");
	newpet->set("is_pet",1);
	switch( ctype ) {
                case "tortoise":
			newpet->set("title","�ڹ�");
			newpet->set("dur",5+random(10));
			newpet->set("spi",1+random(5));
			newpet->set("str",1+random(5));
			newpet->set("agi",1+random(5));
			newpet->set("con",1+random(5));
			if (!random(10))
			newpet->set_skill("petfangyu",1);
			ctype = "һֻ�ڹ�";
                        break;
                case "cat":
		    newpet->set("title","è��");
			newpet->set("dur",1+random(5));
			newpet->set("spi",5+random(10));
			newpet->set("str",1+random(5));
			newpet->set("agi",1+random(5));
			newpet->set("con",1+random(5));
			if (!random(10))
			newpet->set_skill("petfire",1);
			ctype = "һֻè��";
                        break;
                case "pig":
            newpet->set("title","����");
			newpet->set("dur",1+random(5));
			newpet->set("spi",1+random(5));
			newpet->set("str",1+random(5));
			newpet->set("agi",1+random(5));
			newpet->set("con",5+random(10));
			if (!random(10))
			newpet->set_skill("petgedang",1);
			ctype = "һͷ����";
                        break;
                case "bison":
            newpet->set("title","Ұţ");
			newpet->set("dur",1+random(5));
			newpet->set("spi",1+random(5));
			newpet->set("str",5+random(10));
			newpet->set("agi",1+random(5));
			newpet->set("con",1+random(5));
			if (!random(10))
			newpet->set_skill("petqiangji",1);
			ctype = "һͷҰţ";
                        break;
                case "monkey":
            newpet->set("title","����");
			newpet->set("dur",1+random(5));
			newpet->set("spi",1+random(5));
			newpet->set("str",1+random(5));
			newpet->set("agi",5+random(10));
			newpet->set("con",1+random(5));
			if (!random(10))
			newpet->set_skill("petbisha",1);
			ctype = "һֻ����";
                        break;
		default:
			return notify_fail("����û����Ҫ�Ķ�����\n");
	}
	newpet->set("owner",me->query("id"));
	newpet->set("possessed",me);
	newpet->set("name",cname);
	newpet->set("shouming",9999);
	newpet->set("obedience",100);
	newpet->set("id",cid);
	newpet->set("level",1);
	newpet->set("chengzhang",random(20)+20);
	newpet->save();
	ctype = ctype + cname;
	destruct(newpet);
	gold->add_amount(-10000);
	me->add("score",-10000);
    me->start_busy(1);
	command("chat "+ me->query("name") +"��������������"+ctype+"��"+HIC"��Ҫ�ú��չ���Ŷ��");
	command("say ���ˣ������Ŵ�һ�����ڣ����������壩�����С�����ͻ��ܹ����ģ�\n");
        seteuid(getuid());
	return 1;
}
int check_legal_name(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 2) || (strlen(name) > 40 ) ) {
                write("�Բ����������ֱ�����һ����ʮ�������֡�\n");
                return 0;
        }
        while(i--) {
                if( name[i]<=' ' ) {
                        write("�Բ����������ֲ����ÿ�����Ԫ��\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("�Բ������ֱ��������ġ�\n");
                        return 0;
                }
        }
        return 1;
}

int check_legal_id(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 3) || (strlen(name) > 20 ) ) {
                write("�Բ���Ӣ�����ֱ�����������ʮ���֡�\n");
                return 0;
        }

	return 1;
}
