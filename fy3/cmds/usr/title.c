// title by tiandi 让玩家可以自己换称号

inherit F_CLEAN_UP;
    string *name= ({
   "可以使用的称号",
   "可以使用的称号",
   "可以使用的称号",
   "可以使用的称号",
   "可以使用的称号",
   "可以使用的称号",
   "可以使用的称号",
   "可以使用的称号",
   "可以使用的称号",
   "可以使用的称号",
   "可以使用的称号",
   "可以使用的称号",
   "可以使用的称号",
   "可以使用的称号",
   "可以使用的称号",
   "可以使用的称号",
   "可以使用的称号",
   "可以使用的称号",
   "可以使用的称号",
   "可以使用的称号",
   "可以使用的称号",
   "可以使用的称号",
   "可以使用的称号",
   "可以使用的称号",
   "可以使用的称号",
   "可以使用的称号",
   "可以使用的称号",
   "可以使用的称号",
   "可以使用的称号",
   "可以使用的称号",
   "可以使用的称号",
   "可以使用的称号",   });   

int main(object me, string arg)
{
	int i;
	i = 1;
	if( !arg ) 
		{
		write("你现在称号是【" + me->query("title") + "】。\n");
		write("你目前的可以使用的称号有：\n");
		if (me->query("m_success/小娟"))
			{
			write("英雄救美\n");
			name[i]="英雄救美";
			i++;
			}			
		if (me->query("m_success/莽林"))
			{
			write("穿越莽林的猴子\n");
			name[i]="穿越莽林的猴子";
			i++;
			}			
		if (me->query("m_success/鱼汤"))
			{
			write("鱼汤专家\n");
			name[i]="鱼汤专家";
			i++;
			}	
		if (me->query("m_success/蝴蝶泉"))
			{
			write("探险先锋\n");
			name[i]="探险先锋";
			i++;
			}			
		if (me->query("m_success/精钢园桶"))
			{
			write("破坏王\n");
			name[i]="破坏王";
			i++;
			}			
		if (me->query("m_success/老云寨"))
			{
			write("独闯老云寨\n");
			name[i]="独闯老云寨";
			i++;
			}			
		if (me->query("m_success/底舱"))
			{
			write("暗访底舱\n");
			name[i]="暗访底舱";
			i++;
			}	
		if (me->query("m_success/清平"))
			{
			write("撞破了脑袋\n");
			name[i]="撞破了脑袋";
			i++;
			}			
		if (me->query("m_success/武当掌门的秘密"))
			{
			write("偷鸡摸狗\n");
			name[i]="偷鸡摸狗";
			i++;
			}			
		if (me->query("m_success/郭嵩阳"))
			{
			write("破剑破人破功夫\n");
			name[i]="破剑破人破功夫";
			i++;
			}	
		if (me->query("m_success/祭雨"))
			{
			write("呼风唤雨\n");
			name[i]="呼风唤雨";
			i++;
			}			
		if (me->query("m_success/识破天宗"))
			{
			write("自古正邪不两立\n");
			name[i]="自古正邪不两立";
			i++;
			}			
		if (me->query("m_success/巧开五行铜人"))
			{
			write("插针插到手酸\n");
			name[i]="插针插到手酸";
			i++;
			}			
		if (me->query("m_success/勇保经书"))
			{
			write("勇保经书\n");
			name[i]="勇保经书";
			i++;
			}	
		if (me->query("m_success/七仙女阵"))
			{
			write("七个女人和一个男人的故事\n");
			name[i]="七个女人和一个男人的故事";
			i++;
			}			
		if (me->query("m_success/木舟"))
			{
			write("心灵手巧\n");
			name[i]="心灵手巧";
			i++;
			}	
		if (me->query("m_success/罗刹牌"))
			{
			write("跑来跑去\n");
			name[i]="跑来跑去";
			i++;
			}			
		if (me->query("m_success/孽龙"))
			{
			write("屠龙使者\n");
			name[i]="屠龙使者";
			i++;
			}			
		if (me->query("m_success/古玉牌"))
			{
			write("八壁合一\n");
			name[i]="八壁合一";
			i++;
			}			
		if (me->query("m_success/白石"))
			{
			write("闲着无事踩两脚\n");
			name[i]="闲着无事踩两脚";
			i++;
			}	
		if (me->query("m_success/铁雪"))
			{
			write("拨开草丛现牛羊\n");
			name[i]="拨开草丛现牛羊";
			i++;
			}			
		if (me->query("m_success/七星剑"))
			{
			write("好奇心害死人\n");
			name[i]="好奇心害死人";
			i++;
			}			
		if (me->query("m_success/勾魂使者"))
			{
			write("胆大过人\n");
			name[i]="胆大过人";
			i++;
			}			
		if (me->query("m_success/通缉"))
			{
			write("盖世英豪\n");
			name[i]="盖世英豪";
			i++;
			}	
		if (me->query("lifecook")>19)
			{
			write("一代名厨\n");
			name[i]="一代名厨";
			i++;
			}			
		if (me->query("lifedoctor")>19)
			{
			write("医死人不偿命\n");
			name[i]="医死人不偿命";
			i++;
			}			
		if (me->query("lifecombine")>10)
			{
			write("以多换少\n");
			name[i]="以多换少";
			i++;
			}			
		if (me->query("lifeweapon")==100)
			{
			write("铸剑大师\n");
			name[i]="铸剑大师";
			i++;
			}			
		if (me->query("lifearmor")==100)
			{
			write("制甲神童\n");
			name[i]="制甲神童";
			i++;
			}			
		if (me->query("lifexiang")==10)
			{
			write("镶钻王老五\n");
			name[i]="镶钻王老五";
			i++;
			}			
		return 1;

	}
	i=0;
	while (i<sizeof(name))
		{
		if (arg != name[i])
			i++;
		else 	
			{
			me->set("title",name[i]);
			write("你的称号已经设为【"+name[i]+"】。\n");
			return 1;
			}
		}
	write("你不可以使用这个称号。\n");
	return 1;
}

int help(object me)
{
     write(@HELP
指令格式: title <可以使用的称号>

这个指令让你(玩家)知道现在他有哪些称号可以使用。

HELP
    );
    return 1;
}

