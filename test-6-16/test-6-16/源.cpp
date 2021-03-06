/******************************************************
项目二：学生成绩管理系统
专业           学号             姓名            成绩

要求：生成菜单，菜单中的每项功能由一个函数完成
注意：请观察函数的形参如果是数组的定义方式以及在调用函数时传递数组的格式

1.统计学生数countStuNum()
2.统计分数段人数countScoreSegment()，以柱状图形式显示分数段情况。
3.统计最高分countMaxScore()
4.最低分countMinScore()
5.平均分countAverageScore()
6.成绩中值countMedian()
7.线性查找linerSearchScore()
8.拆半查找binSearchScore()
9.添加成绩appendScore()（在有效分数的最后添加成绩,数组元素-1表示这是数组最后一个数，为无效数）
10.插入成绩insertScore()（在指定位置插入成绩）
11.删除某个指定位置的成绩deleteScore()
12.冒泡排序bubbleSort()
13.交换算法swap()
14.对成绩逆序重排reverseSort()
15.显示所有有效成绩displayArray()
**********************************************************/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 30  //成绩数组总长度
#define SEGMENTSIZE 11  //分数段总共有0-10，总计11个段
#define FAILURE -1  //返回失败结果
#define SUCCESS 1   //返回成功结果
#define ASCEND 1    //升序
#define DECEND -1   //降序

//函数申明
int countStuNum(int array[], int length); //统计学生数函数countStuNum
void countScoreSegment(int array[], int Len, int segment[], int segmentLen);//统计分数段人数
int countMaxScore(int array[], int len);//统计最高分
int countMinScore(int array[], int len);//统计最低分
float countAverageScore(int array[], int len);//统计平均分
float countMedian(int array[], int len);//统计成绩中值
int linerSearchScore(int array[], int len, int searchNum);//线性查找
int binSearchScore(int array[], int len, int searchNum);//拆半查找
int appendScore(int array[], int length, int appendScore);//添加成绩
int insertScore(int array[], int length, int insertScore, int insertPossition);//插入成绩
int deleteScore(int array[], int length, int deletePossition);//删除成绩
void bubbleSort(int array[], int length, int sortOrder);//冒泡排序
void reverseSort(int array[], int length); //逆序重排
void displayArray(int array[]);  //显示数组所有有效分数
int checkBoundary(int inputValue, int min, int max); //键盘输入数据有效边界检查
void swap(int* a, int* b);//交换算法
void versionAbout();//程序版本说明

void main()
{
	//注：数组中有25个学生分数，其中最一个-1表示该元素之前的数组元素值为有效分数。
	int score[SIZE] = { 78,65,23,34,56,87,90,100,45,88,54,95,63,66,89,54,64,77,63,56,0,86,97,94,30,-1 };//给score[1]到score[25]赋初值。
	int i;
	int scoreSegment[SEGMENTSIZE] = { 0 };//此数组用于存放统计各分数段的人数，分数段为0-10
	int stuNumber, maxScore, minScore, searchArrayPosition;
	int searchScore, appendScoreNum, insertScoreNum, result, arrayPossition;
	int order;//排序方向
	float averageScore, medianScore;
	enum Status { GAMEOVER, CONTINUE };
	int choiceNum;
	enum Status gameStatus;


	do
	{

		gameStatus = CONTINUE;
		printf("\n\t\t学  生  成  绩  管  理  系  统  1.3 \n\t\t\tDesigned by HuangX\n");
		printf("\n\t1.统计学生数\t\t\t2.统计分数段人数\n\n");
		printf("\t3.统计最高分\t\t\t4.统计最低分\n\n");
		printf("\t5.统计平均分\t\t\t6.统计中值\n\n");
		printf("\t7.线性查找\t\t\t8.拆半查找\n\n");
		printf("\t9.添加成绩\t\t\t10.插入成绩\n\n");
		printf("\t11.删除某个指定位置的成绩\t12.冒泡排序\n\n");
		printf("\t13.逆序重排\t\t\t14.显示所有有效成绩\n\n");
		printf("\t15.版本修正说明\n\n");
		printf("\t0.退出\n\n\t请选择功能：");
		scanf_s("%d", &choiceNum);
		fflush(stdin);//清除键盘缓冲区的数，否则当输入字符时会出现死循环
		switch (choiceNum)
		{
		case 0:
			gameStatus = GAMEOVER;
			break;
		case 1:
			//统计学生数
			stuNumber = countStuNum(score, SIZE); //详细的统计计算见着函数
												  //调用函数统计有效分数的学生人数，
												  //把分数的数组名score传给函数中的输入参数array，
												  //（注意，这里只传数组名）,把score数组的大小SIZE传给函数中的输入参数length
												  //countStuNum(score,SIZE)计算后返回的值放到stuNumber。

			printf("\n\t1.有效学生分数的个数是：%d\n\n", stuNumber);
			displayArray(score);//显示所有有效的分数
			system("pause"); //程序暂停
			break;
		case 2:
			//统计分数段人数
			printf("请在这里编写分段统计的程序或调用函数\n");
			system("pause"); //程序暂停
			break;
		case 3:
			//统计最高分
			printf("请在这里编写统计最高分的程序或调用函数\n");
			system("pause"); //程序暂停
			break;
		case 4:
			//统计最低分
			printf("请在这里编写统计最低分的程序或调用函数\n");
			system("pause"); //程序暂停
			break;
		case 5:
			//统计平均分
			float averageScore;
			//编写一个计算平均分函数，调用函数统计平均分,赋值给averageScore。
			printf("\n\t5.平均分是：%.1f\n\n", averageScore);
			system("pause"); //程序暂停
			break;
		case 6:
			//编写统计中值程序

			printf("中值是?");
			system("pause"); //程序暂停
			break;
		case 7:
			//线性查找
			printf("线性查找到分数\n");
			system("pause"); //程序暂停
			break;
		case 8:
			//编写拆半查找程序

			system("pause"); //程序暂停
			break;
		case 9:
			//添加成绩

			system("pause"); //程序暂停
			break;
		case 10:
			//插入成绩

			system("pause"); //程序暂停
			break;
		case 11:
			//删除成绩

			system("pause"); //程序暂停
			break;

		case 12:
			//对成绩冒泡排序

			system("pause"); //程序暂停
			break;

		case 13:
			//对成绩逆序重排

			system("pause"); //程序暂停
			break;
		case 14:
			//显示所有有效成绩
			displayArray(score);
			system("pause"); //程序暂停
			break;
		case 15:
			//版本说明
			versionAbout();
			break;
		default:
			printf("\n\t选择错误，请在显示项目对应的数字中重新选择!\n");
			system("pause"); //程序暂停
		}
		system("cls");//清屏
		choiceNum = -1;  //解决第二轮进入菜单选择时，输入字符或标点符号等非数字时出现的错误
	} while (gameStatus != GAMEOVER);

}  //end main()

   /**********************************************
   1.函数功能说明：统计有效分数的学生人数
   形参说明： array[]  要进行统计的数组名称
   length   该数组的总长度
   返回值：   返回有效学生人数
   **********************************************/
   //注意形参是数组的定义格式，通常形参如果是数组，
   //则除了定义数组名外，还得定义数组的长度，以防止越界
int countStuNum(int array[], int length)
{
	int i, stuNumber = 0;
	for (i = 0; i < length; i++)
		if (array[i] != -1) stuNumber++; //因为数组的结尾是-1，统计非-1的个数
		else break;
	return stuNumber;

} //countStuNum(int array[],int length)


  /**********************************************
  2.函数功能说明：统计各分数段人数
  形参说明： array[]   要进行统计的数组名称
  len       该数组有效学生数
  segment[] 用于存放分数段人数
  返回值：   无
  **********************************************/
void countScoreSegment(int array[], int Len, int segment[], int segmentLen)
{

	//柱状显示各分类段的人数
	printf("\n\t2. 统计显示各分类段的人数\n");



}//end countScoreSegment(int array[],int len)


 /**********************************************
 3.函数功能说明：统计最高分
 形参说明： array[] 要进行统计的数组名称
 len     该数组有效学生数
 返回值：   返回最高分
 **********************************************/
int countMaxScore(int array[], int len)
{
	int max = 100;

	return max;

}  //countMaxScore(int array[],int len)


   /**********************************************
   4.函数功能说明：统计最低分
   形参说明： array[]  要进行统计的数组名称
   len      该数组有效学生数
   返回值：   返回最低分
   **********************************************/
int countMinScore(int array[], int len)
{
	int min = 0;

	return min;

}//end countMinScore(int array[],int len)


 /**********************************************
 5.函数功能说明：统计平均分
 形参说明： array[] 要进行统计的数组名称
 len     该数组有效学生数
 返回值：   返回平均分
 **********************************************/
float countAverageScore(int array[], int len)
{
	int i, sum = 0;

	return (float)sum / len;

}//end countAverageScore

 /****************************************************************
 6.函数功能：求全班学生成绩的中值
 (如果数组元素个数为偶数，中值等数组中间两个元素的平均值)
 形参说明：int array[]  存放全班成绩的数组
 int len  数组的长度
 返回值:   成绩的中值
 *****************************************************************/
float countMedian(int array[], int len)
{
	float median;
	//冒泡排序

	return median;
}
/**********************************************
6.函数功能说明：线性查找某一分数在数组中的位置
形参说明： array[]   要进行统计的数组名称
len       该数组有效学生数
searchNum 要查找的数
返回值：   找到了返回分数在数组中的位置(下标)
找不到，返回-1
**********************************************/
int linerSearchScore(int array[], int len, int searchNum)
{
	int i, flag = 0, f_at;
	if (flag == 1) return f_at;
	else return FAILURE;
}//end linerSearchScore(int array[],int len,int searchNum)


 /**********************************************
 7.函数功能说明：拆半查找某一分数在数组中的位置
 形参说明： array[]   要进行统计的数组名称
 len       该数组有效学生数
 searchNum 要查找的数
 返回值：   找到了返回分数在数组中的位置(下标)
 找不到，返回-1
 **********************************************/
int binSearchScore(int array[], int len, int searchNum)
{
	int flag = 0, left = 0, right = len - 1, mid; //要注意防止right下标越界
	if (flag == 1) return mid;
	else return FAILURE;//找不到
}//end binSearchScore(int array[],int len,int searchNum)


 /**********************************************
 8.函数功能说明：添加成绩（在有效分数的最后添加成绩）
 形参说明： array[]     要进行统计的数组名称
 length      该数组总长度
 appendScore 要添加的成绩
 返回值：   SUCCESS  表示添加成功
 FAILURE  表示数组已满，无法添加
 **********************************************/
int appendScore(int array[], int length, int appendScore)
{
	return FAILURE; //这是数组的最后一个元素，即数组已满

}//end appendScore(int array[],int len,int appendScore)


 /**********************************************
 9.函数功能说明：插入成绩（在指定位置插入成绩）
 形参说明： array[]         要进行统计的数组名称
 length          该数组总长度
 insertScore     要插入的成绩
 insertPossition 要插入的位置
 返回值：   SUCCESS  表示插入成功
 FAILURE  表示数组已满，无法插入
 **********************************************/
int insertScore(int array[], int length, int insertScore, int insertPossition)
{
	return SUCCESS;

}//end insertScore(int array[],int length,int insertScore)


 /**********************************************
 10.函数功能说明：删除某个指定位置的成绩
 形参说明： array[]         要进行统计的数组名称
 length          该数组总长度
 deletePossition 要删除元素的位置
 返回值：   SUCCESS  表示删除成功
 **********************************************/
int deleteScore(int array[], int length, int deletePossition)
{

	return SUCCESS;
}//end deleteScore(int array[],int len,int deletePossition)


 /**********************************************
 11.函数功能说明：冒泡排序
 形参说明： array[]     要进行统计的数组名称
 length      该数组总长度
 sortOrder   排序方向
 ASCEND   升序
 DECEND   降序

 返回值：   无
 **********************************************/
void bubbleSort(int array[], int length, int sortOrder)
{
	int i, j, k, stuNum;
	stuNum = countStuNum(array, length);//得到有效成绩的学生人数
	for (i = stuNum; i > 0; i--)   //i指第i轮排序
	{
		k = i;   //k指一轮中要比较交换的元素个数
		if (sortOrder == ASCEND)  //升序排列
		{
			for (j = 0; j < k - 1; j++)
				if (array[j] > array[j + 1])
					swap(&array[j], &array[j + 1]);
		}
		else   //降序排列
		{
			for (j = 0; j < k - 1; j++)
				if (array[j] < array[j + 1])
					swap(&array[j], &array[j + 1]);
		}
	} //end for
}//end bubbleSort(int array[],int length,int sortOrder)

 /**********************************************
 12.函数功能说明：交换算法
 形参说明： *a   待交换变量的地址
 *b   待交换变量的地址
 返回值：   无
 **********************************************/
void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}//swap(int *a,int *b)



 /**********************************************
 13.函数功能说明：逆序重排
 形参说明： array[]         要进行统计的数组名称
 length          该数组总长度
 返回值：   无
 **********************************************/
void reverseSort(int array[], int length)
{
	int left, right, stuNum;
	stuNum = countStuNum(array, length);//得到有效成绩的学生人数
	right = stuNum - 1;//注意防止下标越界
	for (left = 0; left <= right; left++, right--)
		swap(&array[left], &array[right]); //交换算法

}//end reverseSort(int array[],int length)


 /**********************************************
 14.函数功能说明：显示数组所有有效分数
 形参说明： array[]  要显示的数组名称
 返回值：   无
 **********************************************/
void displayArray(int array[])
{
	int i, len;
	len = countStuNum(array, SIZE); //调用函数countStuNum()得到数组有效分数个数
	printf("\t\t");
	for (i = 0; i < len; i++)
	{
		printf("[%2d] %-5d", i, array[i]); //输出所有有效分数
		if ((i + 1) % 5 == 0) printf("\n\t\t");  //每行五个数
	}//end for
	printf("\n");
}//end displayArray(int array[],int len)

 /**********************************************
 15.函数功能说明：程序版本修正说明
 形参说明： 无
 返回值：   无
 **********************************************/
void versionAbout()
{
	system("cls");//清屏
	printf("\n\t\t学  生  成  绩  管  理  系  统  1.3 版本说明\n\t\t\tDesigned by HuangX\n");
	printf("\n******************************************************************************\n");
	printf("\n# 1.1版本修改了多次调用统计分数段函数时，数据累加的问题 \n");
	printf("\n\t感谢2017闽台班潘劲同学发现的Bug! \n");

	printf("\n# 1.2版本修改了第二轮进入菜单选择时，输入字符或标点符号等非数字时出现的错误问题 \n");
	printf("\n\t感谢2017闽台班陈俊瑜、郑义恒同学发现的Bug! \n");

	printf("\n# 1.3版本修改了分数段统计时，数组第0个元素未被统计的错误问题 \n");
	printf("\n\t感谢2017闽台班王创星同学发现的Bug! \n");
	printf("\n# 1.3版本还对9，10，11三个功能增加了必要的边界出错提示信息! \n");
	printf("\n******************************************************************************\n\n");
	system("pause"); //程序暂停
	system("cls");//清屏
}
/**********************************************
函数功能说明：键盘输入数据有效边界检查
形参说明： inputValue  输入的分数
min         边界的最小值
max         边界的最大值
返回值：   分数有效，返回分数
分数无效，返回FAILURE
**********************************************/
int checkBoundary(int inputValue, int min, int max)
{
	if (inputValue <= max && inputValue >= min)
		return inputValue;
	else return FAILURE;
}//end inputScore(int inputScore

