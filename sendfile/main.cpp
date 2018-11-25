#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/sendfile.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <chrono>

using namespace std;

#define INPUT_FLIE_NAME ("test.file")
#define WRITE_OUTPUT_FILE_NAME ("output_write.file")
#define SENDFILE_OUTPUT_FILE_NAME ("output_send.file")

uint64_t GetCurrentTimeByMS()
{
    auto time_now = chrono::system_clock::now();
    auto duration_in_ms = chrono::duration_cast<chrono::milliseconds>(time_now.time_since_epoch());
    return duration_in_ms.count();
}

int TestWrite()
{
	int in_fd = -1;
	if((in_fd = open(INPUT_FLIE_NAME, O_RDONLY)) < 0) 
	{
		fprintf(stderr, "open %s failed!\n", INPUT_FLIE_NAME);
		return -1;
	}
	
	struct stat file_state;
	memset(&file_state, 0, sizeof(file_state));
	if(0 != fstat(in_fd, &file_state)) 
	{
		fprintf(stderr, "fstat failed!\n");
		close(in_fd);
		return -1;
	}
	
	int out_fd = -1;
	if((out_fd = open(WRITE_OUTPUT_FILE_NAME, O_WRONLY | O_CREAT | O_TRUNC, 0777)) < 0)
	{
		fprintf(stderr, "open %s failed!\n", WRITE_OUTPUT_FILE_NAME);
		close(in_fd);
		return -1;
	}
	

	int file_size = file_state.st_size;
	char* file_buffer = new char[file_size];
	uint64_t start = GetCurrentTimeByMS();
	FILE* file_in = fdopen(in_fd, "r");
	FILE* file_out = fdopen(out_fd, "w");
	fread(file_buffer, file_size, 1, file_in);
	size_t write_nums = fwrite(file_buffer, file_size, 1, file_out);
	fclose(file_out);
//	fsync(out_fd);
	//fflush(file_out);
        printf("read/write cost time: %dms\n", GetCurrentTimeByMS() - start);
	fclose(file_in);
	close(in_fd);
	close(out_fd);
	delete [] file_buffer;
	file_buffer = nullptr;
	return 0;
}

int TestSendfile()
{
	int in_fd = -1;
        if((in_fd = open(INPUT_FLIE_NAME, O_RDONLY)) < 0)
        {       
                fprintf(stderr, "open %s failed!\n", INPUT_FLIE_NAME);
                return -1;
        }
        
        struct stat file_state;
        memset(&file_state, 0, sizeof(file_state));
        if(0 != fstat(in_fd, &file_state))
        {       
                fprintf(stderr, "fstat failed!\n");
                close(in_fd);
                return -1;
        }
        
        int out_fd = -1;
        if((out_fd = open(SENDFILE_OUTPUT_FILE_NAME, O_WRONLY | O_CREAT | O_TRUNC, 0777)) < 0)
        {       
                fprintf(stderr, "open %s failed!\n", SENDFILE_OUTPUT_FILE_NAME);
                close(in_fd);
                return -1;
        }
	uint64_t start = GetCurrentTimeByMS();
	sendfile(out_fd, in_fd, nullptr, file_state.st_size);
	close(out_fd);
	printf("sendfile cost time: %dms\n", GetCurrentTimeByMS() - start);
	close(in_fd);
	return 0;
}

int main()
{
	TestWrite();
	TestSendfile();
	return 0;
}
