// drinkmonk.c
inherit NPC;
int go_in();
void create()
{
    set_name("�������",({"drink monk","monk"}));
    set("long","����һ��ɮ��ɮ�ײ��ף���ͷ�ҷ��Ĺ���\n");
    set("gender","����");
    set("no_arrest",1);
    set("age",42);
    set("int",20);
    set("cor",30);
    set("cps",20);
    set("gin",500);
    set("max_gin",500);
    set("eff_gin",500);
    set("max_kee",500);
    set("eff_kee",500);
    set("kee",500);  
    set("max_sen",500);
    set("sen",500);    
    set("eff_sen",500);
    set("combat_exp",1000000);
    set_skill("force",100);
    set_skill("lotusforce",100);
    set_skill("unarmed",100);
    set_skill("parry",50);
    set_skill("dodge",50);
    set("force",1000);
    set("max_force",1000);
    set("force_factor",100);
    map_skill("force","lotusforce");
    set("attitude", "heroism");
    set("inquiry",([
          "meat": (: go_in :),
          "��"  : (: go_in :) ,
          "���丳" : "�˸����˳��̲����䣬����������֮������������������\n",
           ])   );
    set("chat_chance",1);     
    set("chat_msg",({
          "��������������������䶯Ҳ��������ޣ��׵繲�������侲Ҳ������𩾵���ǿ����䣡��\n",
          "��������ƿ����ǿ���һ��\n",
          }) );

    setup();
    carry_object(__DIR__"obj/cloth")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

int greeting(object me)
{
 
    if( !me || environment(me) != environment() ) return 1;
    say ("�������˵������������һ���ɡ�\n");
    return 1;
}
int go_in()
{
    command("say �㲻˵�ҵ����ˣ������Ұ���������ȥ����˵����");
    message_vision("$N˫���������룬�ߵ�С���ſ�\n",this_object());
    command("cat");
    command("cat");
    message_vision("$N���Ż������ƿ�һ�ߣ��������˽�ȥ��\n",this_object());
    this_player()->start_busy(1); 
    call_out("disap",1);
 
    return 1;
}
void disap()
{
	object room;
   message_vision("��Ȼ���ڡ���ѽ��һ����������Ǻॡ�һ�����죬�Լ�������Ҳ���ڵ���\n",this_object());
	room=find_object("/d/tieflag/maoroom1");
	if(!objectp(room))
	room = load_object("/d/tieflag/maoroom1");
	this_object()->move(room);
                call_out("greeting2", 2);
}
int greeting2()
{

    say ("�������˵���������˷��ӽ���ȥ�����Ӿ�Ҫ�Ǵ��ˡ������������ҲҪץ����������\n");
    say ("������л������ˣ����ѷ�������ص���\n");
    destruct( this_object());
    return 1;
}

