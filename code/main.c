#include<stdio.h>
//#include<io.h> // Note: This is non-standard, common on Windows (MSVC)
#include<string.h>
#include"ptom.h"

void declare()
{
	printf("******************************************\n");
	printf("Version:%.2f\n",ptom_getVersion());
	// Original: 本软件不得用于商业用途，仅做学习交流。\n
	printf("This software is not intended for commercial use, for learning and exchange purposes only.\n");
	// Original: 声明：本软件切勿外泄\n
	printf("Disclaimer: Do not leak this software.\n");
	// Original: 输入exit退出\n
	printf("Enter exit to quit.\n");
	printf("******************************************\n");
}

int main(int argc, char *argv[])
{
    if(argc != 3) {
        declare();
        printf("Usage: %s <input_p_file> <output_m_file>\n", argv[0]);
        printf("Use --version to display version info\n");
        return 1;
    }

    if(strcmp(argv[1], "--version") == 0) {
        declare();
        return 0;
    }

    if(ptom_init() == 0) {
        printf("Initialization failed\n");
        return 1;
    }

    if(ptom_parse(argv[2], argv[1])) {
        printf("Conversion successful\n");
    } else {
        printf("Conversion failed\n");
    }

    ptom_deinit();
    return 0;
}

#if 0 // This section remains inactive
int main()
{
	//test lots of file
	
	// Original path component: 代码 (dàimǎ) means "Code"
	char p_dir[] = "D:\\Reverse\\ptom\\Code\\test\\p";
	char m2_dir[] = "D:\\Reverse\\ptom\\Code\\test\\m2";
	char pfile[256] = {0};
	char mfile[256] = {0};	
	long handle; // Note: long for handle might be 32-bit specific, intptr_t is better if available
	struct _finddata_t fileinfo; // Note: _finddata_t, _findfirst, _findnext, _findclose are Windows-specific (<io.h>)
	int pos = 0;

    if(ptom_init() == 0)
    {
    	// Original: 初始化失败\n
    	printf("Initialization failed\n");
    	return -1; // Note: Returning non-zero usually indicates failure
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
			mfile[pos-1] = 'm'; // Assumes filenames end in ".p"
			if(!ptom_parse(mfile,pfile))
			{
				printf("%s > %s convert failed\n",pfile,mfile);
			}				
		}while(_findnext(handle,&fileinfo)==0);
		_findclose(handle);
	}
	
	ptom_deinit();
	return 1;	// Note: Standard C typically returns 0 for success
}
#endif