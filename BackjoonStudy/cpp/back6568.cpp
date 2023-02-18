#pragma warning(disable:4996)
#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (true)
	{
		int Memory[32] = { 0 };
		for (int i = 0; i < 32; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				int bit;
				//EOF
				if (scanf("%1d", &bit) < 0)
					return 0;
				Memory[i] = Memory[i] * 2 + bit;
			}
		}

		int programCnt = 0;
		// adder = �����
		int adder = 0;
		while (true)
		{
			// ���� 3�ڸ� bit�� ����� �ݴϴ�.
			int command = Memory[programCnt] / 32;
			// ���� 5�ڸ� ��Ʈ�� ������ݴϴ�.(������ ����)
			int operand = Memory[programCnt] % 32;

			if (command == 7) { break; }  // HLT ���α׷��� �����Ѵ�.

			programCnt = (programCnt + 1) % 32;
			//2^8 = 256
			switch (command)
			{
				case 0: // STA x   �޸� �ּ� x�� ������� ���� �����Ѵ�.
					Memory[operand] = adder;
					break;

				case 1: // LDA x   �޸� �ּ� x�� ���� ������ �ҷ��´�.
					adder = Memory[operand];
					break;

				case 2: // BEQ x   ������� ���� 0�̸� PC ���� x�� �ٲ۴�.
					if (adder == 0) { programCnt = operand; }
					break;

				case 3: // NOP     �ƹ� ���굵 ���� �ʴ´�.
					break;

				case 4: // DEC     ����� ���� 1 ���ҽ�Ų��.
					adder = (adder + 255) % 256;
					break;

				case 5: // INC     ����� ���� 1 ������Ų��.
					adder = (adder + 1) % 256;
					break;

				case 6: // JMP x   PC ���� x�� �ٲ۴�.
					programCnt = operand;
					break;
			}
		}

		for (int i = 7; i >= 0; i--)
			printf("%1d", (adder >> i) & 1);
		printf("\n");
	}
	return 0;
}