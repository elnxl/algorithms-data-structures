#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


struct stroka {
	long value;
	char* string;
};


stroka* mergesort(stroka* buf1, stroka* buf2, int l, int r);
	

bool mbstring(const char* inp) {
	unsigned char frst = inp[0];
	if (frst < '0' || frst > '9') {
		return true;
	}
	int i = 1;
	while (inp[i] != '\n') {
		if (inp[i] != ' ') {
			if (inp[i] < '0' || inp[i] > '9') {
				return true;
			}
		}
		else {
			return false;
		}
		i++;
	}
	return false;
}


int main(int argc, char* argv[]) {
	if (argc != 3) {
		return 1;
	}
	int count;
	FILE* fp;
	fp = fopen(argv[1], "rb");
	if (fp == nullptr) {
		return 2;
	}
	_fseeki64(fp, 0, SEEK_END);
	size_t filesize = _ftelli64(fp);
	char* cur = new char[filesize + 1];
	cur[filesize] = '\0';
	_fseeki64(fp, 0, SEEK_SET);
	if (fread(cur, filesize, 1, fp) != 1) {
		return 2;
	}
	count = (int)strtol(cur, nullptr, 10);
	if (count == 0) {
		if (cur[0] == '0') {
			return 0;
		}
		else {
			return 3;
		}
	}
	unsigned short ind = 0;
	while (cur[ind] != '\n' && cur[ind] != '\r') {
		if (cur[ind] < '0' || cur[ind] > '9') {
			return 3;
		}
		ind++;
	}
	auto* arr = new stroka[count];
	int index = 0;
	for (size_t i = 0; i < filesize; i++) {
		if (cur[i] == '\n') {
			cur[i] = '\0';
			arr[index].string = cur + i + 1;
			if (mbstring(arr[index].string)) {
				return 3;
			}
			arr[index].value = strtol(arr[index].string, nullptr, 10);
			if (arr[index].value == 0 && arr[index].string[0] != '0') {
				return 3;
			}
			index++;
		}
	}
	if (index != count) {
		return 3;
	}
	auto* barr = new stroka[count];
	stroka* result = mergesort(arr, barr, 0, count - 1);
	FILE* fpw;
	fpw = fopen(argv[2], "wb");
	if (fpw == nullptr) {
		return 2;
	}
	if (fprintf(fpw, "%i\n", count) < 0) {
		return 2;
	}
	for (int i = 0; i < count; i++) {
		if (fprintf(fpw, "%s\n", result[i].string) < 0) {
			return 2;
		}
	}
	return 0;
}

stroka* mergesort(stroka* buf1, stroka* buf2, int l, int r) {
	if (l == r) {
		buf2[l] = buf1[l];
		return buf2;
	}
	int m = (r + l) / 2;
	stroka* lb = mergesort(buf1, buf2, l, m);
	stroka* rb = mergesort(buf1, buf2, m + 1, r);
	stroka* to;
	if (lb == buf2) {
		to = buf1;
	}
	else {
		to = buf2;
	}
	int sorttmp = l;
	int curr = m + 1;
	for (int i = l; i < r + 1; i++) {
		if (curr > r) {
			to[i] = lb[sorttmp];
			sorttmp++;
			continue;
		}
		if (sorttmp > m) {
			to[i] = rb[curr];
			curr++;
			continue;
		}
		if (lb[sorttmp].value < rb[curr].value) {
			to[i] = lb[sorttmp];
			sorttmp++;
		}
		else {
			to[i] = rb[curr];
			curr++;
		}
	}
	return to;
}