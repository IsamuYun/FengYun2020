// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
int give_soup();
void create()
{
        set_name("����", ({ "mengpo", "meng"}) );
        set("gender", "Ů��" );
        set("age", 220);
        set("long", 
"��˵����׷���ϰ鵽�ظ�֮�������������䣬�������ã�
����������׼���������������⣬��Ϊ�������������𣩺ã�����������Ϊ����
����������һ��������ʹ����ȴ�����Ŀ�ʹ���������ŵ������һ�պù�һ�ա�
Ͷ�����˶����ڴ���һ��������ֻ�֮·��
\n");
        set("combat_exp", 5000);
        set("attitude", "friendly");
	set_temp("apply/astral_vision",1);
        set("chat_chance", 1);
        set("chat_msg", ({
                "���Ŷ���˵�������������˲��ٿ�ɣ��������ɣ���\n",
                "����˵�������ӣ���·ǰ��һ��ɣ���\n",
        }) );
        set("inquiry", ([
                "������" : (: give_soup:),
                "soup" : (: give_soup:)

        ]));
	setup();
	add_money("silver", 5);
        carry_object("/obj/cloth")->wear();
}

int give_soup()
{
	object obj;
if( !query("given"))
	{
message_vision("$N���������ַ�Ҩ��һ�����ݸ�$n��\n",this_object(),this_player());
command("say �������������ȣ��������·��\n");
obj = new(__DIR__"obj/dang");
obj->move(this_player());
if(!random(10))set("given",1);
	}
else
command("say ���ϣ��ո����⣬����ţ��Ҿ�ȥ�ٰ�һ����\n");
	return 1;
}

void reset()
{
delete("given");
}
