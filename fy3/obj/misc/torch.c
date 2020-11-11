/****************************************************************
 * This file is a part of the TianXia(����, The World)'s MudLib.*
 * Please retain the header if you use it.     -- Micro@TianXia *
 ****************************************************************/

// File     : torch.c
// Purpose  : ���
// Created  : 1998-08-03
// By       : Micro@TianXia

// History  : 98-08-03  Micro@TianXia �����ļ�

#include <ansi.h>

inherit ITEM;

// �������������ɺ���
void create()     
{
	set_name( "���", ({ "torch" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "֦");
		set("long", @LONG
����һ֦��ѡ�������õ��������ߡ�
������� light ������������ unlight ��Ϩ������
LONG
                );
          	set("value", 100);
        	set("fuel", 600);       // ����ȼ�յ�ʱ������
	}
}

// �����������ʼ������
void init()
{
	add_action("light_torch", "light");
	add_action("unlight_torch", "unlight");
}

// ��������ȼ��ѵĴ���
int light_torch( string str )
{
	if( !id(str) ) return 0;
	if( !query("fuel") )
		return notify_fail( "�������Ѿ������ˡ�\n");

	if( query("light") ) 
		return notify_fail( "�������Ѿ���ȼ�ˡ�\n");

	write("�㽫��ѵ�����\n");
	set("light", 1);
	call_out( "burn_out", query("fuel") );
	return 1;
}

// ������Ϩ���ѵĴ���
int unlight_torch(string str)
{
	if( !id(str) ) return 0;
	if( !query("fuel") )
		return notify_fail("̫���ˣ��������Ѿ������ˡ�\n");

	if( !query("light") )
		return notify_fail("�����ѻ�û�е�ȼ�����Ϩ��\n");

	write("�㽫���Ϩ��\n");
	set( "light", 0 );
	set( "fuel", remove_call_out("burn_out") );
	return 1;
}

// �����������ȫȼ�պ�Ĵ���
void burn_out()
{
	object owner;

        // ��ʾ����Ѿ�������
	owner = environment(this_object());
	if( living(owner) )
		tell_object( owner,"��Ļ�ѻ�����˼��£�Ϩ���ˡ�\n");

        // ����Ļ��û�м�ֵ�����һ���Ϩ��
	set( "value", 0 );      
	set( "fuel", 0 );
	set( "light", 0 );
}

// ��������ѵ���������
// ע�ͣ�1.��Ҫ����������ѵ�����״̬��ȼ�գ�Ϩ���չ⡣
string extra_long()
{
	if(query("fuel"))
		return "��ѻ��" + (query("light") ? "��ȼ���š�\n" : "Ϩ���ˡ�\n");
	return "��ѻ���Ѿ��չ��ˡ�\n";
}

