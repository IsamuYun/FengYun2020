inherit NPC;
string ask_me(); 
int do_shouge(string arg); 
void reward(object me); 

void create()
{
        set_name("��ũ", ({ "old farmer", "farmer" }) );
        set("gender", "����");
        set("age", 46);
        set("long",
                "һλ�����ʮ��ũ��\n"
        );
        set_skill("blade", 10+random(50));
        set("inquiry", ([ 
"��ׯ��" : (: ask_me :), 
"shouge" : (: ask_me :), 
]));
        setup();
        add_money("silver", 1);
        carry_object("/u/wudang/obj/liandao")->wield();

}

void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_shouge", "shouge");

}

string ask_me() 
{ 
object me = this_player(); 

if (this_object()->is_busy()) 
return "�����ں�æ����Ȼ�ɣ�"; 
if (me->query("combat_exp") > 100000) 
return "�����ϸ����δ�������˰ɣ�"; 

if (me->query("kee") < 50) 
return "�㿴�����е��ۣ�ЪЪ�ȵ�ˮ������̫���ˡ�"; 

{ 
me->set_temp("laonong/shouge", 1); 
return "�ã�������ո�ׯ�ڰ�(shouge)��"; 
}
}

int do_shouge(string arg) 
{ 
object me = this_player(); 

if (me->is_busy()) 
return notify_fail("��������æ��\n"); 

if (! me->query_temp("laonong/shouge")) 
{ 
message_vision("$n����������������ȥ��ʼ�ո�ׯ�ڡ�" 
"������$N��$n�����ⲻ�������������ʲô��\n", 
this_object(), me); 
return 1; 
} 

message_vision("$n������������������������ȥ��ʼ�ո�ׯ�ڣ�$N���˵��˵�ͷ��\n", 
this_object(), me); 
reward(me); 
return 1; 
} 

void reward(object me) 
{ 
object coin; 

me->delete_temp("laonong/shouge"); 

coin = new("/obj/money/coin"); 
coin->set_amount(20 + random(100)); 
coin->move(this_player()); 
this_object()->start_busy(2);
message_vision("$N��$n�������Ǹ���Ĺ�Ǯ��\n", 
this_object(), me); 
if (me->query("combat_exp") < 100000) 
{
me->add("potential", 3); 
me->add("combat_exp", 10 + random(10)); 
} 
me->receive_damage("kee", 30); 
me->start_busy(4); 
} 

