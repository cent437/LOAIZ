#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	double start, end; // ���塞 ��६���� ��� ��।������ �६��� �믮������
	
	int i=0, j=0, r;
	int a[200][200], b[200][200], c[200][200], elem_c;

	srand(time(NULL)); // ���樠�����㥬 ��ࠬ���� ������� ��砩��� �ᥫ
	start = clock();
	while(i<200)
	{
		while(j<200)
		{
			a[i][j]=rand()% 100 + 1; // ������塞 ���ᨢ ��砩�묨 �᫠��
			j++;
		}	// O(n)
		i++;
	} 		// O(n^2)
	srand(time(NULL)); // ���樠�����㥬 ��ࠬ���� ������� ��砩��� �ᥫ
	i=0; j=0;
	while(i<200)
	{
		while(j<200) 
		
			b[i][j]=rand()% 100 + 1; // ������塞 ���ᨢ ��砩�묨 �᫠��
			j++;
		}	// O(n)
		i++;
	}		// O(n^2)

	for(i=0;i<200;i++)
	{
		for(j=0;j<200;j++)
		{
			elem_c=0;
			for(r=0;r<200;r++)
			{
				elem_c=elem_c+a[i][r]*b[r][j];
				c[i][j]=elem_c;
			} // O(n)
		}	// O(n*n)
	} 		// O(n^3)
	end = clock();
	printf("Time of matrix multiplication: %lf sec.", (end - start) / 1000);
   
	return 0;
}

