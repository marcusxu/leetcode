class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1)
			return s;
		if (numRows == 2){
			int length = s.length();
			int colum = length / 2 + 1;
			char* buff[2];
			buff[0] = new char[colum];
			buff[1] = new char[colum];
			int pointer = 0;
			for (int i = 0; i < 2; ++i)
				for (int j = 0; j < colum; ++j)
					buff[i][j] = ' ';
			int i=0, j=0;
			while (pointer < length){
				buff[i][j] = s[pointer];
				++pointer;
				if (i == 1){
					++j;
					i = 0;
				}
				else
					++i;
			}
			string result;
			for (int i = 0; i < numRows; ++i)
				for (int j = 0; j < colum; ++j)
					if (buff[i][j] != ' ')
						result.push_back(buff[i][j]);
			return result;
		}
		//建立缓冲区
		int length = s.length();
		int colums = (length / (numRows - 1)) + 1;
		char **buff = new char*[numRows];
		for (int i = 0; i < numRows; ++i)
			buff[i] = new char[colums];
		for (int i = 0; i < numRows; ++i)
			for (int j = 0; j < colums; ++j)
				buff[i][j] = ' ';
		//遍历
		int pointer = 0,builderX = 0,builderY = 0;
		bool down = true;
		while (pointer < length){
			buff[builderX][builderY] = s[pointer];
			++pointer;
			if (down){
				if (builderX == numRows - 1){
					++builderY;
					--builderX;
					down = false;
				}
				else{
					++builderX;
				}
			}
			else{
				if (builderX == 1){
					++builderY;
					builderX = 0;
					down = true;
				}
				else{
					--builderX;
				}
			}
		}
		//输出
		string result;
		for (int i = 0; i < numRows; ++i)
			for (int j = 0; j < colums; ++j)
				if (buff[i][j] != ' ')
					result.push_back(buff[i][j]);
		return result;
	}
};
