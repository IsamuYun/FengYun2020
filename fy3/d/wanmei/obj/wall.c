inherit ITEM;
void create()
{
        set_name("ʯ��", ({ "wall" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "�����ܵ�ʯ���ϣ������������Ƶ����Σ�����һ��ָ����\n");
                set("no_shown",1);
                set("material", "stone");
                set("no_get",1);
                set("no_drop",1);
                set("skill", ([
                        "name":                 "lingxiyizhi",     
                        "exp_required":         1000,           
                        "sen_cost":             30,     
                        "difficulty":   30,     
                        "max_skill":    80              
                ]) );
        }
}
void init()
{
  add_action("do_study","study");
}
int do_study(string arg)
{
    string book;
    string sena;
    if(!arg || sscanf(arg, "%s %d", book, sena)!=2 ) return 0;
    if (book == "wall" || book  == "ʯ��")
     if (!this_player()->query_temp("mark/lu"))
    {
        tell_object(this_player(),"½С��Ц����Ҫѧ��Ϭһָ����Ҫ�����Ұɣ�\n");
        return 1;
      } 
}

