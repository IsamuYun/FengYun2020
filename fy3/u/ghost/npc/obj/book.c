// book.c

inherit ITEM;

void create()
{
	int	i;

        string *names = ({
                "���׾���", "��̫��ȭ�ס�", "�����Ž��ס�", "��������ͼ��",
                "��̫���ڹ����š�"
        });

        string *skills= ({
                "changelaw", "taiji", "three-sword", "five-steps", "taijiforce"
        });

	i = random(5);
        set_name( names[i], ({ "book" }));
        set_weight(100);
        set("value", 100000);
        set("unit", "��");
        set("long", "����һ�������䵱�������书���鼮��\n");
        set("skill", ([
                "name":                 skills[i],
                "exp_required": 0,                
                "sen_cost":             30,     
                "difficulty":   30,            
                "max_skill":    40           
                                            
        ]) );
}
