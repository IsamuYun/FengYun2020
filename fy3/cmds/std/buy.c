//buy.c

inherit F_CLEAN_UP;
void create() { seteuid(getuid()); }
void pay_him( object who, int amount);
int affordable(object who, int amount);
string value_string(int value)
{
	if( value < 1 ) value = 1;
	else if( value < 100 )
		return chinese_number(value) + "��Ǯ";
	else
		return chinese_number(value/100) + "��"
			+ (value%100? "��" + chinese_number(value%100) + "��Ǯ": "");
}


int main(object me, string arg)
{
	string item, targ;
	object ob, owner,*inv;
	int price, afford, change;

	if( me->is_busy() || !arg || sscanf(arg, "%s from %s", item, targ)!=2 )
		return notify_fail("ָ���ʽ��buy <ĳ��> from <ĳ��>\n");

	if( !objectp(owner = present(targ, environment(me))) )
		return notify_fail("��Ҫ��˭������\n");

// by tiandi for trading system
	if( userp(owner) ) 
	{
		message_vision("$N����$n����" + item + "����\n", me, owner);
		if (!owner->query_temp("in_trade"))
			return notify_fail("�Է�������ȫ�޶����ԡ�\n");
		inv = all_inventory(owner);
		 ob = present(item,owner);
		if (!ob)
			return notify_fail("�Է�����û������Ҫ�Ķ�����\n");
		if(!ob->query_temp("trading"))
			return notify_fail("�Է���Ȼ����������������ź��Է�����û������۵���˼��\n");
		if(!ob->query_temp("price"))
			return notify_fail("�˻���۸��е����⣬��ͣ���ס�\n");
		price = ob->query_temp("price");
		if( afford = affordable(me,price) )  
		{
			pay_him(me, afford - price);
			afford = affordable(owner,0);
			pay_him(owner,afford + price/10*9);
			ob->move(me);
			ob ->delete_temp("no_get");
			ob ->delete_temp("no_drop");
			ob ->delete_temp("price");
			ob ->delete_temp("trading");
			tell_object(owner,me->query("name")+"����������۵�"+ob->query("name")+"���۳�˰����ʵ�ʻ����"+value_string(price/10*9)+"��\n");
			tell_object(me,"�㹺����"+owner->query("name")+"���۵�"+ob->query("name")+"����ʵ��֧����"+value_string(price)+"��\n");

			return 1;
		} else
			return notify_fail("���Ǯ������\n");
		me->start_busy(2);
	}

//	notify_fail("�Է�����û������Ҫ�Ķ�����\n");
//	if( (price = owner->buy_object(me, item)) < 1 ) return 0;
	if( (price = owner->buy_object(me, item)) < 1 )
	return notify_fail("�Է�����û������Ҫ�Ķ�����\n");
	if( afford = affordable(me, price) ) {
		pay_him(me, afford-price); //by tiandi,˭д��code����д���淶��������������Ϊafford-price��һ��������.�Ǹ�bug.
		owner->compelete_trade(me, item);
		owner->add("richness",price);
		return 1;
	} else
		return notify_fail("���Ǯ������\n");
	me->start_busy(1);
}

int help(object me)
{
   write( @HELP
ָ���ʽ: buy <something> from <someone>

��һָ��������Դ�ĳЩ����������Ʒ��
HELP
   );
   return 1;
}

void pay_him(object who, int amount)

{
	object ob;
        object cash, tencash, gold, silver, coin;
        tencash = present("tenthousand-cash_money", who);
        cash = present("thousand-cash_money", who);
        gold = present("gold_money",who);
        silver = present("silver_money",who);
        coin = present("coin_money",who);
	if(tencash) destruct(tencash);
        if(cash) destruct(cash);
        if(gold) destruct(gold);
        if(silver) destruct(silver);
        if(coin) destruct(coin);

	if( amount < 1 ) amount = 1;
        if( amount/1000000 ) {
                ob = new(TECASH_OB);
                ob->set_amount(amount/1000000);
                ob->move(who);
                amount %= 1000000;
        }
        if( amount/100000 ) {
                ob = new(THCASH_OB);
                ob->set_amount(amount/100000);
                ob->move(who);
                amount %= 100000;
        }
	if( amount/10000 ) {
		ob = new(GOLD_OB);
		ob->set_amount(amount/10000);
		ob->move(who);
		amount %= 10000;
	}
        if( amount/100 ) {
                ob = new(SILVER_OB);
                ob->set_amount(amount/100);
                ob->move(who);
                amount %= 100;
        }
	if( amount ) {
		ob = new(COIN_OB);
		ob->set_amount(amount);
		ob->move(who);
	}
}

int affordable(object me, int amount)
{
        int total;
        object cash, tencash, gold, silver, coin;

        tencash = present("tenthousand-cash_money", me);
        cash = present("thousand-cash_money", me);
        gold = present("gold_money",me);
        silver = present("silver_money",me);
        coin = present("coin_money",me);

        total = 0;
        if( tencash) total += tencash->value();
        if( cash) total += cash->value();
        if( gold ) total += gold->value();
        if( silver ) total += silver->value();
        if( coin ) total += coin->value();

        if( total < amount ) return 0;

        return total;
}
