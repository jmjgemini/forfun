/* date 2013/10/24
 * author jinminjie
 * mail: jmjgeminix@gmail.com
 */

#include <stdio.h>

static int max = 0;
static int max_level = 0;
static int sum = 0;

int powi(int x,int y)
{
	if (y <= 0)
		return 1;
	else
		while(--y)
			x*=x;
	return x;
}

int get_level(int x)
{
	int level = 0;
	while(x/=10)
		level++;
	level++;
	return level;
}
void dfs(int level,int ori,int new,int num_of_1)
{
	/* 剪枝 */
	if (level > max_level)
		return;
	int new_num = ori + new * powi(10,level-1);
	if (new_num > max)
		return;
	 /**********/
	if (new == 1)
		num_of_1++;
	if (new != 0)/* 避免0开头的重复计数 */
		sum+=num_of_1;
	for(int i = 0;i<= 9;i++)
	{
		dfs(level+1,new_num,i,num_of_1);
	}
}
int main(void)
{
	sum = 0;
	printf("please input the num:");
	scanf("%d",&max);
	max_level = get_level(max);
	dfs(0,0,0,0);
	printf("the num of '1' is %d\n",sum);
	return 0;
}
