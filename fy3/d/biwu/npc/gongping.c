// ɽè(adx) by snow 2000-05-15

//inherit F_MASTER;
//inherit F_UNIQUE;
inherit NPC;
inherit F_SAVE;

#include <ansi.h>

string status_color(string current, string str);
string delcolor(string str2);
int fenzu(string *inv);
int xuanbu();
int huihe();
int start_biwu();
int keep_biwu(string id);
int end_biwu();
int jieshu_biwu(string id1, string id2);

#ifndef NPCDATA
#define NPCDATA "/d/biwu/npc/"
#endif
#define GONGPING NPCDATA + "gongping"

#define	WIZLEVEL	5
#define	TIME		60

#define BIWUA	"������"
#define BIWUB	"��̨��"
#define BIWUC	"������"
#define BIWUD	"ѭ����"

string query_save_file()
{
	return GONGPING;
}

int save()
{
	string file;

	if( stringp(file = this_object()->query_save_file()) ) {
		assure_file(file+ __SAVE_EXTENSION__);
		return save_object(file);
	}
	return 0;
}

int restore()
{
	string file;

	if( stringp(file = this_object()->query_save_file()) )
		return restore_object(file);
	return 0;
}

void create()
{
	seteuid(getuid());

	if (!restore()) {
	set_name("��ƽ��", ({ "gongping zi", "gongping", "zi" }) );
	set("title", HIW"�ĺ�ɢ��"NOR);
	set("long",
		"����һλ�ɷ���ǵ�������ˣ����������ķ����Ժ�������������˽��\n");
	set("gender", "����" );
	set("age", 40);
	set("biwudahui",1);
	set("no_clean_up",1);

	setup();
	carry_object("/clone/misc/cloth")->wear();        
	}
	else {
		set("id", "gongping zi");
		set_name(query("name"), ({  "gongping zi", "gongping", "zi" }));
	setup();      
	}
}

void init()
{
	object me = this_player();

	add_action("do_canjia", "canjia");
	add_action("do_menpai", "menpai");
	add_action("do_list", "list");

	if (wizardp(me) && wiz_level(me) >= WIZLEVEL) {
		add_action("do_start", "start");
		add_action("do_biwu", "biwu");
		add_action("do_agree", "agree");
		add_action("do_diss", "dissent");
		add_action("do_del", "del");
	}
}

int do_start(string arg)
{
	object ob=this_object();
	int i=ob->query("biwudahui");
	int a;
        string *inv, *str, *menpai;

	if(!arg)
		return notify_fail("��Ҫ��ʼ������䣿\n");

        if(ob->query("start/start"))
                return notify_fail("�������Ѿ���ʼ�ˡ�\n");

	if(arg=="xunhuan") {
		inv=keys(ob->query("biwu_baoming"));
		if(sizeof(inv)<4)
			return notify_fail("��������̫���ˣ��������޷���ʼ��\n");
                message("channel:chat",HIW"�����䳡����"+CHINESE_D->chinese_number(i)+
			"�������һ���Ӻ�ʼ���������ѱ���ѡ���ٵ����䳡����\n"NOR,users());
		ob->set("start/start", arg);
		fenzu(inv);
		return 1;
	}

	str=keys(ob->query("menpai_baoming"));
	for(a=0; a<sizeof(str); a++) {
		if(arg==str[a]) {
			if(ob->query("fangshi")!=BIWUC)
				return notify_fail("������Ƚ����䷽ʽ�л�Ϊ��������\n");
			menpai=keys(ob->query("menpai_baoming/"+arg));
			if(sizeof(menpai)<4)
				return notify_fail("��������̫���ˣ��������޷���ʼ��\n");
			message("channel:chat",HIW"�����䳡��"HIM+arg+HIW"���Ŵ����ѡ��"+
			"����һ���Ӻ�ʼ���������ѱ���ѡ���ٵ����䳡����\n"NOR,users());
			ob->set("start/start", arg);
			fenzu(menpai);
			return 1;
		}
	}
	return notify_fail("������ɻ�δ������룡\n");
}

int fenzu(string *inv)
{
        object ob=this_object();
	string id1, id2, id3, id4, id;
	mapping fenzu, str;
	int a=1;
	int b=1;
	int i, j, k;

	ob->delete("huihe");
	ob->delete("fenzu");
	ob->delete("jifen");
	ob->add("start/lunxu", 1);
	ob->set("start/huihe", 1);
	ob->set("start/cxu", 1);
	for(i=0; i<sizeof(inv); i++) {
		id=inv[i];
		if(find_player(id)) {
			ob->set("fenzu/"+a+"/"+b, id);
			b=b+1;
		}
		if(b>4) { b=1; a=a+1; }
	}
	
	fenzu=ob->query("fenzu");
	for(i=1; i<(sizeof(fenzu)+1); i++) {
		str=ob->query("fenzu/"+i);
		for(j=1; j<(sizeof(str)+1); j++) {
			id=ob->query("fenzu/"+i+"/"+j);
			if(j==1) id1=id;
			if(j==2) id2=id;
			if(j==3) id3=id;
			if(j==4) id4=id;
		}
		if((sizeof(str))==4) {
			k=k+1;
			ob->set("huihe/"+k+"/ob1", id1);
			ob->set("huihe/"+k+"/ob2", id2);
			k=k+1;
			ob->set("huihe/"+k+"/ob1", id3);
			ob->set("huihe/"+k+"/ob2", id4);
			k=k+1;
			ob->set("huihe/"+k+"/ob1", id1);
			ob->set("huihe/"+k+"/ob2", id3);
			k=k+1;
			ob->set("huihe/"+k+"/ob1", id2);
			ob->set("huihe/"+k+"/ob2", id4);
			k=k+1;
			ob->set("huihe/"+k+"/ob1", id1);
			ob->set("huihe/"+k+"/ob2", id4);
			k=k+1;
			ob->set("huihe/"+k+"/ob1", id2);
			ob->set("huihe/"+k+"/ob2", id3);
		}
		if((sizeof(str))==3) {
			k=k+1;
			ob->set("huihe/"+k+"/ob1", id1);
			ob->set("huihe/"+k+"/ob2", id2);
			k=k+1;
			ob->set("huihe/"+k+"/ob1", id2);
			ob->set("huihe/"+k+"/ob2", id3);
			k=k+1;
			ob->set("huihe/"+k+"/ob1", id1);
			ob->set("huihe/"+k+"/ob2", id3);
		}
		if((sizeof(str))==2) {
			k=k+1;
			ob->set("huihe/"+k+"/ob1", id1);
			ob->set("huihe/"+k+"/ob2", id2);
		}
		if((sizeof(str))==1) {
			k=k+1;
			ob->set("huihe/"+k+"/ob1", id1);
		}
	}
	ob->delete("chuxian");
	save();
	xuanbu();
	return 1;
}

int xuanbu()
{
        object ob=this_object();
	int j=ob->query("start/lunxu");
	string *menpai=ob->query("fenzu");
	string *str, id, msg;
	int a, b;

	message("channel:chat",HIW"�����䳡����ƽ����������������"+
		CHINESE_D->chinese_number(j)+"�ֱ���������£�\n",users());

	for(a=1; a<(sizeof(menpai)+1); a++) {
		msg=HIW"��"+CHINESE_D->chinese_number(a)+"�飺";
		str=ob->query("fenzu/"+a+"/");
		for(b=1; b<(sizeof(str)+1); b++) {
			id=ob->query("fenzu/"+a+"/"+b+"");
			msg+=""+find_player(id)->query("name")+"("+id+")\t";
		}
		message("channel:chat",HIW""+msg+"\n",users());
	}
	remove_call_out("start_biwu");
	call_out("start_biwu", TIME);
	return 1;
}

int start_biwu()
{
	object ob=this_object();
	int i=ob->query("start/lunxu");
	int j=ob->query("start/huihe");
	string id1, id2;
	string *str=keys(ob->query("huihe"));
	object ob1, ob2;

	ob->add("start/huihe", 1);
	ob->add("start/cxu", 1);

	if((sizeof(str))==1) {
		ob->delete("start/lunxu");
		ob->delete("start/huihe");
		ob->delete("start/cxu");
		end_biwu();
		return 1;
	}

	if( (sizeof(ob->query("huihe/"+j)))==1 ) {
		id1=ob->query("huihe/"+j+"/ob1");
		keep_biwu(id1);
	}

	id1=ob->query("huihe/"+j+"/ob1");
	id2=ob->query("huihe/"+j+"/ob2");
	ob1=find_player(id1);
	ob2=find_player(id2);

	if(!ob1 && !ob2) {
		message("channel:chat",HIW"�����䳡����ƽ������������"+
			CHINESE_D->chinese_number(i)+"�֣���"+
			CHINESE_D->chinese_number(j)+"�غϱ��䣺\n"+
			"                ����"+"("+id1+")��("+id2+")"+
			"��ȱ�󣡱��غ�ȡ����������һ�֣�\n",users());
		remove_call_out("start_biwu");
		call_out("start_biwu", 2);
	}
	if(!ob1) {
		message("channel:chat",HIW"�����䳡����ƽ������������"+
			CHINESE_D->chinese_number(i)+"�֣���"+
			CHINESE_D->chinese_number(j)+"�غϱ��䣺\n"+
			"                ����("+id1+")ȱ��"+ob2->query("name")+"("+id2+")"+
			"ʤ����\n",users());
		keep_biwu(id2);
	}
	if(!ob2) {
		message("channel:chat",HIW"�����䳡����ƽ������������"+
			CHINESE_D->chinese_number(i)+"�֣���"+
			CHINESE_D->chinese_number(j)+"�غϱ��䣺\n"+
			"                ����("+id2+")ȱ��"+ob1->query("name")+"("+id1+")"+
			"ʤ����\n",users());
		keep_biwu(id1);
	}

	message("channel:chat",HIW"�����䳡����ƽ������������"+
		CHINESE_D->chinese_number(i)+"�֣���"+
		CHINESE_D->chinese_number(j)+"�غϱ��䣺\n"NOR+YEL+
		"                "BLINK+
		ob1->query("name")+"("+id1+")"+"---V.S.---"+
		ob2->query("name")+"("+id2+")\n"NOR,users());
	ob->set("start/biwu_fighter1", id1);
	ob->set("start/biwu_fighter2", id2);
	ob1->set("biwu_fighter", 1);
	ob2->set("biwu_fighter", 1);
	return 1;
}

int keep_biwu(string id)
{
	object ob=this_object();
	string *str=keys(ob->query("huihe"));
	string *inv, *str1, *str2, id1, *fenzu;
	int k=ob->query("start/cxu");
	int i, j;

	if(id=="adx") {
		k=k+1;
	} else {
		ob->add("jifen/"+id, 1);
	}
	if(k>sizeof(str)) {
		ob->delete("jifen/0");
		ob->delete("start/cxu");
		str1=keys(ob->query("fenzu"));

		for(i=1; i<(sizeof(str1)+1); i++) {
			fenzu=keys(ob->query("fenzu/"+i));

			if(sizeof(fenzu)>=3) {
				for(j=1; j<(sizeof(fenzu)+1); j++) {
					id1=ob->query("fenzu/"+i+"/"+j);
					if(ob->query("jifen/"+id1)>=2)
						ob->set("chuxian/"+id1, 1);
				}
			}
			if(sizeof(fenzu)==2) {
				for(j=1; j<(sizeof(fenzu)+1); j++) {
					id1=ob->query("fenzu/"+i+"/"+j);
					if(ob->query("jifen/"+id1)>=1)
						ob->set("chuxian/"+id1, 1);
				}
			}
			if(sizeof(fenzu)==1) {
				id1=ob->query("fenzu/"+i+"/1");
				ob->set("chuxian/"+id1, 1);
			}
		}
		inv=keys(ob->query("chuxian"));
		fenzu(inv);
		return 1;
	}

	remove_call_out("start_biwu");
	call_out("start_biwu", 2);
}

int end_biwu()
{
	object ob=this_object();
	int i=ob->query("biwudahui");
	string *id=keys(ob->query("huihe/1/"));
	string id1, id2;
	object ob1, ob2;

	if(id1=ob->query("huihe/1/ob1")) ob1=find_player(id1);
	if(id2=ob->query("huihe/1/ob2")) ob2=find_player(id2);

	if(sizeof(id)==1) {
		message("channel:chat",HIW"�����䳡����ƽ�����������������ڵ�"+
			CHINESE_D->chinese_number(i)+"����������һ��\n"+
			"        ֻ��"+ob1->query("name")+"("+id1+")"+
			"���ߣ����Ա��䵽�˽�����\n"NOR,users());
		jieshu_biwu(id1, id2);
		return 1;
	}
	ob->set("start/juesai", 1);
	message("channel:chat",HIW"�����䳡����ƽ�����������������ڵ��˵�"+
		CHINESE_D->chinese_number(i)+"������������ʱ���ˣ�\n",users());
	message("channel:chat",HIW"�����䳡����ƽ���������������ɣ�\n"NOR+YEL+
		"                "BLINK+
		ob1->query("name")+"("+id1+")"+"---V.S.---"+
		ob2->query("name")+"("+id2+")\n"NOR,users());
	ob->set("start/biwu_fighter1", id1);
	ob->set("start/biwu_fighter2", id2);
	ob1->set("biwu_fighter", 1);
	ob2->set("biwu_fighter", 1);
	return 1;
}

int jieshu_biwu(string id1, string id2)
{
	object ob=this_object();
	object ob1, ob2;
	string str=ob->query("start/start");
	string msg;
	int i=ob->query("biwudahui");

	if(id1) ob1=find_player(id1);
	if(id2) ob2=find_player(id2);

	if(str=="xunhuan") {
		if(!ob2) {
			message("channel:chat",HIY"                "+
				"�ھ��ǣ�"BLINK+ob1->query("name")+"("+id1+")"+
				"\n"NOR,users());
			msg=""+ob1->query("name")+"("+id1+")";
			ob->set("biwu_jieguo/"+i+"/1", msg);
		} else {
			 message("channel:chat",HIW"�����䳡����ƽ����������������"+
				CHINESE_D->chinese_number(i)+
				"������ᵽ�˽�����\n",users());
			message("channel:chat",HIY"                "+
				"�ھ��ǣ�"BLINK+ob1->query("name")+"("+id1+")"+
				"\n"NOR,users());
			message("channel:chat",WHT"                "+
				"�Ǿ��ǣ�"BLINK+ob2->query("name")+"("+id2+")"+
				"\n"NOR,users());
			msg=""+ob1->query("name")+"("+id1+")";
			ob->set("biwu_jieguo/"+i+"/1", msg);
			msg=""+ob1->query("name")+"("+id2+")";
			ob->set("biwu_jieguo/"+i+"/2", msg);
		}
		ob->add("biwudahui", 1);
		ob1->set("snowzongshi",1);
		ob->delete("biwu_baoming");
	} else {
		if(!ob2) {
			message("channel:chat",HIR"        ף��"+
				BLINK+ob1->query("name")+"("+id1+")"+
				"����"+str+"���Ŵ���ӣ�\n"NOR,users());
		} else {
			message("channel:chat",HIW"�����䳡����ƽ��������������"+
				str+"���Ŵ����ѡ�α��䵽�˽�����\n",users());
			message("channel:chat",HIR"        ף��"+
				BLINK+ob1->query("name")+"("+id1+")"+
				"����"+str+"���Ŵ���ӣ�\n"NOR,users());
		}
		ob->set("biwu_jieguo/"+str,""+ob1->query("name")+"("+id1+")"+"");
		ob->delete("menpai_baoming/"+str);
		msg=HIY""+str+"���Ŵ����"NOR;
		ob1->set("title", msg);
		ob->delete("menpai/"+str+"");
	}
	ob->delete("start");
	ob->delete("jifen");
	ob->delete("huihe");
	ob->delete("fenzu");
	save();
	return 1;
}

int do_list(string arg)
{
	object ob=this_object();
	string *menpai, name, long, *inv, family;
	mapping site;
	int a;

	if(!arg) {
		message_vision(CYN"��ѯ�����ᱨ����� ��(list �μ�)\n"NOR, ob);
		message_vision(CYN"��ѯ�������������� ��(list ����)\n"NOR, ob);
		message_vision(CYN"��ѯ���ɱ��䱨����� ��(list <����������>)\n"NOR, ob);
		return 1;
	}
	if(arg=="����") {
		if(!ob->query("menpai") || sizeof(ob->query("menpai"))<1)
			return notify_fail("���ڱ����ỹû�п�ʼ���ܱ�����\n");

		printf(HIB"\n����"+HBWHT RED"���������Ŵ���ӱ����������"NOR+
			HIB"��������������������������\n"NOR);
		printf(HIB"�� �������� ��  ��   ��   ��  ��  ��  ʦ  ��   ��  ��  �� ��\n"NOR);
		printf(HIB"�ǩ���������������������������������������������������������\n"NOR);

		menpai=keys(ob->query("menpai"));
		for(a=0; a<sizeof(menpai); a++) {
			family=menpai[a];
			site=ob->query("menpai/"+family);
			name=site["name"];
			long=site["long"];
		printf(HIB"��"NOR+"%10s"+HIB"��"NOR+"%16s"+HIB"��"NOR+"%26s"+HIB"��\n"NOR,
			family, name, long);
		}

		printf(HIB"������������������������������������������������������������\n"NOR);
		return 1;
	}

	if(arg=="�μ�") {
		if(arg!=BIWUD)
			return notify_fail("���ڲ��Ǿٰ�������ʱ��\n");
		inv=keys(ob->query("biwu_baoming"));
		printf(CYN"��ƽ�ӵ����������Ѿ������μӱ���������������\n");
		for(a=0; a<sizeof(inv); a++) {
			site=ob->query("biwu_baoming/"+inv[a]+"/");
			printf("%s(%s)\t", site["name"], site["id"]);
			if((a+1)%3 == 0 )
				printf("\n");
		}
		printf("\n"NOR);
		return 1;
	}

	menpai=keys(ob->query("menpai_baoming"));

	if(!ob->query("menpai/"+arg+"/agree"))
		return notify_fail("��ʦ��δ��׼"+arg+"�ٰ����Ŵ����ѡ�α��䣡\n");
	for(a=0; a<sizeof(menpai); a++) {
		if(menpai[a]==arg) {
			inv=keys(ob->query("menpai_baoming/"+arg+"/"));
		printf(CYN"��ƽ�ӵ����������Ѿ������μ�"+arg+"���Ŵ����ѡ�α����������\n");
			for(a=0; a<sizeof(inv); a++) {
				site=ob->query("menpai_baoming/"+arg+"/"+inv[a]);
				printf("%s(%s)\t", site["name"], site["id"]);
				if((a+1)%3==0)
					printf("\n");
			}
		printf("\n"NOR);
		return 1;
		}
	}
	return notify_fail(""+arg+"��û���˱����μ����Ŵ���ӱ��䣡\n");
}

int do_canjia()
{
	object me=this_player();
	object ob=this_object();
	int i=ob->query("biwudahui");
	string str=ob->query("fangshi");
	string id=me->query("id");
	string name=me->query("name");
	string family=me->query("family/family_name");

	if(wizardp(me))
                return notify_fail("��ʦҲҪ�μӱ��䣿������ɽè(adx)֪������ҧ�㣡\n");

	if(me->query("age")<=16)
                return notify_fail("δ��ʮ����Ĳ��ܲμӱ��䣡\n");

	if(ob->query("start/start"))
                return notify_fail("�����Ѿ���ʼ�ˣ����ڲ����ܱ�����\n");

	if(!family) family="������";
		family=delcolor(family);

	if(str==BIWUD) {
		message_vision(CYN"$N��$n�����μӵ�"+CHINESE_D->chinese_number(i)+
			"������ᣡ\n"NOR, me, ob);

		if(ob->query("biwu_baoming/"+id+"/id")==id) {
			message_vision(CYN"$n��$N�������Ѿ��������μӱ����������\n"NOR, me, ob);
			return 1;
		}

		ob->set("biwu_baoming/"+id+"/id", id);
		ob->set("biwu_baoming/"+id+"/name", name);
		ob->set("biwu_baoming/"+id+"/family", family);

		message_vision(CYN"$n�ͳ����Ӱ�$N�����ּ���������\n"NOR, me, ob);
		save();
		return 1;
	}

//	if(str==BIWUC) {
		message_vision(CYN"$N��$n�����μ�"+family+"���Ŵ����ѡ�α��䣡\n"NOR, me, ob);
		if(ob->query("menpai/"+family+"/family")==family) {
			if(!ob->query("menpai/"+family+"/agree")) {
			message_vision(CYN"$n��$N�������ɵı���������ʦ��δ��׼��\n"NOR, me, ob);
				return 1;
			}

			if(ob->query("menpai_baoming/"+family+"/"+id+"/id")==id) {
			message_vision(CYN"$n��$N�������Ѿ��������μӹ��ɵı�������\n"NOR,me,ob);
				return 1;
			}
			ob->set("menpai_baoming/"+family+"/"+id+"/id", id);
			ob->set("menpai_baoming/"+family+"/"+id+"/name", name);
			message_vision(CYN"$n��$N�������Ҽ����ˣ�\n"NOR, me, ob);
			save();
			return 1;
		}
	message_vision(CYN"$n��$N�������ɻ�δ����ٰ����Ŵ����ѡ�εı������룡\n"NOR, me, ob);
	return 1;
//	}
}

int do_menpai()
{
	object me=this_player();
	object ob=this_object();
	string id=me->query("id");
	string name=me->query("name");
	string family=me->query("family/family_name");

	if(wizardp(me))
                return notify_fail("��ʦҲҪ��֯���䣿������ɽè(adx)֪����ҧ�㣡\n");

	if(!family)
                return notify_fail("�㻹δ�����κ����ɣ�\n");
		family=delcolor(family);

	if(me->query("combat_exp")<100000)
                return notify_fail("����书̫���ˣ�����������룡\n");

	if(ob->query("start/start"))
                return notify_fail("�����Ѿ���ʼ�ˣ����ڲ��������룡\n");

//	if(ob->query("fangshi")!=BIWUC)
//		return notify_fail("���ڲ������ɾٰ����Ŵ���ӱ���ѡ�δ���ʱ��\n");

	message_vision(CYN"$N��$n����"+family+
		"Ҫ��ٰ����Ŵ���ӱ���ѡ�δ�ᣡ\n"NOR, me, ob);

	if(ob->query("menpai/"+family+"/family")==family) {
		message_vision(CYN"$n��$N����"+ob->query("menpai/"+family+"/name")+
			"("+ob->query("menpai/"+family+"/id")+")"+
			"�Ѿ�����ٰ����Ŵ���ӱ���ѡ�δ������\n"NOR, me, ob);
		return 1;
	}

	ob->set("menpai/"+family+"/id", id);
	ob->set("menpai/"+family+"/name", name);
	ob->set("menpai/"+family+"/family", family);
	ob->set("menpai/"+family+"/long", "�ȴ���ʦ����У�");
	message_vision(CYN"$n�ͳ����Ӽ�����������$N�����ã����ǵõȴ���ʦ����׼��\n"NOR, me, ob);
	save();
	return 1;
}

int do_biwu(string arg)
{
	object ob = this_object();
	int i=ob->query("biwudahui");

	if(!arg) {
		printf(HIW"��"+HIG"���䷽ʽ"+HIW"��"NOR+
			"%s"+HIM+BIWUA+"\t%s"+
			HIM+BIWUB+"\t%s"+
			HIM+BIWUC+"\t%s"+
			HIM+BIWUD+"\n"NOR,
			status_color(ob->query("fangshi"), BIWUA),
			status_color(ob->query("fangshi"), BIWUB),
			status_color(ob->query("fangshi"), BIWUC),
			status_color(ob->query("fangshi"), BIWUD) );
		return 1;
	}
	switch(arg) {
	case "geren":
		ob->set("fangshi", BIWUA);
                message("channel:chat",
                        HIW"�����䳡�����ڱ��䳡����ʹ�ã���ҿ�������ǰ�����ԣ�\n"NOR,users());
		save();
		return 1;
	case "leitai":
		ob->set("fangshi", BIWUB);
                message("channel:chat",
                        HIW"�����䳡�����ڱ��䳡���Ű��ޣ���ӭ��λ����ǰ�����ޣ�\n"NOR,users());
		save();
		return 1;
	case "menpai":
		ob->set("fangshi", BIWUC);
                message("channel:chat",
                        HIW"�����䳡�����ڱ��䳡���Ÿ����ɱ��䣬����ƽ�����룡\n"NOR,users());
		save();
		return 1;
	case "xunhuan":
		ob->set("fangshi", BIWUD);
                message("channel:chat",
                        HIW"�����䳡�����ڵ�"+CHINESE_D->chinese_number(i)+
			"������ᱨ����ʼ��"+"����μ�������ƽ�ӱ�����\n"NOR,users());
		save();
		return 1;
	case "stop":
		ob->delete("fangshi");
                message("channel:chat",
                        HIW"�����䳡�����ڱ��䳡��ͣʹ��һ��ʱ�䣡\n"NOR,users());
		save();
		return 1;
	default:
		return notify_fail("Ŀǰ���䷽ʽֻ�У�"+
			BIWUA+"��"+BIWUB+"��"+BIWUC+"��"+BIWUD+"��\n");
	}
}

int do_agree(string arg)
{
	object me=this_player();
	object ob=this_object();
	string menpai, str, family, name, id;

	if(sscanf(arg, "%s %s", menpai, str)!=2)
		return notify_fail("��Ҫ��׼�ĸ����ɾٰ����Ŵ����ѡ�α������룿\n");

	family=ob->query("menpai/"+menpai+"/family");

	if(!family)
		return notify_fail("������ɻ�δ������룡\n");

	name=ob->query("menpai/"+menpai+"/name");
	id=ob->query("menpai/"+menpai+"/id");
	str="ͬ�� �� "+str+"";
	ob->set("menpai/"+menpai+"/agree", "ͬ��");
	ob->set("menpai/"+menpai+"/long", str);
	ob->set("menpai_baoming/"+family+"/"+id+"/id", id);
	ob->set("menpai_baoming/"+family+"/"+id+"/name", name);
	message_vision(CYN"$N��׼��"+family+"�ٰ����Ŵ����ѡ�α������룡\n"NOR, me);
	message("channel:chat",
		HIW"�����䳡����ʦ��׼��"+family+"�ٰ����Ŵ����ѡ�α������룬"+
		"�����ǰ�������μӣ�\n"NOR,users());
	save();
	return 1;
}

int do_diss(string arg)
{
	object me=this_player();
	object ob=this_object();
	string menpai, str, family, name, id;

	if(sscanf(arg, "%s %s", menpai, str)!=2)
		return notify_fail("��Ҫ����ĸ����ɾٰ����Ŵ����ѡ�α������룿\n");

	family=ob->query("menpai/"+menpai+"/family");

	if(!family) 
		return notify_fail("������ɻ�δ������룡\n");

	name=ob->query("menpai/"+menpai+"/name");
	id=ob->query("menpai/"+menpai+"/id");
	str="��ͬ�� ��Ϊ "+str+"";
	ob->set("menpai/"+menpai+"/long", str);
	ob->delete("menpai/"+menpai+"/agree");
	ob->delete("menpai_baoming/"+family+"");
	message_vision(CYN"$N�����"+family+"�ٰ����Ŵ����ѡ�α������룡\n"NOR, me);
	save();
	return 1;
}

int do_del(string arg)
{
	object me=this_player();
	object ob=this_object();
	string family;

	family=ob->query("menpai/"+arg+"/family");

	if(!family) 
		return notify_fail("������ɻ�δ������룡\n");

	ob->delete("menpai/"+family+"");
	ob->delete("menpai_baoming/"+family+"");
	message_vision(CYN"$Nɾ����"+family+"�ٰ����Ŵ����ѡ�α������룡\n"NOR, me);
	save();
	return 1;
}

string status_color(string current, string str)
{
	if(str==current) return BLINK HIG"��"NOR;
	return HIR"��"NOR;
}

string delcolor(string str2)
{
	str2 = replace_string(str2, BLK,"");
	str2 = replace_string(str2, RED,"");
	str2 = replace_string(str2, GRN,"");
	str2 = replace_string(str2, YEL,"");
	str2 = replace_string(str2, BLU,"");
	str2 = replace_string(str2, MAG,"");
	str2 = replace_string(str2, CYN,"");
	str2 = replace_string(str2, WHT,"");
	str2 = replace_string(str2, HIR,"");
	str2 = replace_string(str2, HIG,"");
	str2 = replace_string(str2, HIY,"");
	str2 = replace_string(str2, HIB,"");
	str2 = replace_string(str2, HIM,"");
	str2 = replace_string(str2, HIC,"");
	str2 = replace_string(str2, HIW,"");
	str2 = replace_string(str2, NOR,"");
	str2 = replace_string(str2, BLINK,"");
	return str2;
}
