#include <ansi.h>
inherit ITEM;
void create()
{	set_name("�������",({"kala ok","singer"}));
	set("long","һ����������������Ļ�ʵ磬�������졣����һ����(sing)\n");
	set("unit","��");
	set("value",99);
	set("no_get",1);
}
void init()
{	add_action("do_sing","sing");
}

int do_sing(string arg)
{ string msg;
  string *color=({HIR,HIG,HIY,HIB,HIM,HIC,HIW});
  string *word=({

"�����и��������",
"��~~~~~ѽ~~��~~~~~~"});
  string *verb=({

"����ɤ��������ȫ�س�����",
"������ͭ��ɤ�Ӻ��ţ�",
"�������������������"});
  string *eff=({

"����Ҫ�꣬��Ҫ�ꡣ��",
"���ۣ������ˣ���",
"�����Ķ�ð������ơ���"});
  object me=this_player();
  msg=color[random(sizeof(color))]+"$N"+verb[random(sizeof(verb))];
  if(arg) msg+=arg;
  else msg+=word[random(sizeof(word))];
  if(random(20)<5) msg+=eff[random(sizeof(eff))];  
  message_vision(msg+NOR"\n",me);
return 1;
}
