#include<stdio.h>
#include<io.h>
#include<string.h>
#include"ptom.h"

void declare()
{
	printf("******************************************\n");
	printf("Version:%.2f\n",ptom_getVersion());
	printf("���������������ҵ��;������ѧϰ������\n");
	printf("�����������������й\n");
	printf("����exit�˳�\n");
	printf("******************************************\n");
}

#if 1 
int main()
{
	char pfile[512], mfile[512];
    if(ptom_init() == 0)
    {
    	printf("��ʼ��ʧ��\n");
    	return 0;
	}
	
	while(1)
	{
		declare();
		printf("������p�ļ�·��:");
		scanf("%511s",pfile);

        if(strcmp(pfile,"exit") == 0)
			break;

		printf("������m�ļ�·��:");
		scanf("%511s",mfile);
        if(strcmp(mfile,"exit") == 0)
			break;
			
		if(ptom_parse(mfile,pfile))
		{
			printf("ת���ɹ�\n");
		}else
		{
			printf("ת��ʧ��\n");
		}
		system("pause");
		system("cls");
	}
	ptom_deinit();
	return 1;
}
#endif

#if 0 
int main()
{
	//test lots of file
	
	char p_dir[] = "D:\\Reverse\\ptom\\����\\test\\p";
	char m2_dir[] = "D:\\Reverse\\ptom\\����\\test\\m2";
	char pfile[256] = {0};
	char mfile[256] = {0};	
	long handle;
	struct _finddata_t fileinfo;
	int pos = 0;

    if(ptom_init() == 0)
    {
    	printf("��ʼ��ʧ��\n");
    	return -1;
	}
	
	sprintf(pfile,"%s\\*.p",p_dir);
	if((handle = _findfirst(pfile,&fileinfo)) == -1L)
	{
		printf("can't find any p file in %s\n",pfile);
		return -1;
	}else
	{
		do{
			sprintf(pfile,"%s\\%s",p_dir,fileinfo.name);
			pos = sprintf(mfile,"%s\\%s",m2_dir,fileinfo.name);
			mfile[pos-1] = 'm';
			if(!ptom_parse(mfile,pfile))
			{
				printf("%s > %s convert failed\n",pfile,mfile);
			}				
		}while(_findnext(handle,&fileinfo)==0);
		_findclose(handle);
	}
	
	ptom_deinit();
	return 1;	
}
#endif 
