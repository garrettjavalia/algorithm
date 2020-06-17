#include <iostream>
#include <algorithm>

int weight[101] = { 0 };//����
int value[101] = { 0 };//��ġ
int memory[101][1000001] = { 0 };//�κ������� �ִ밡ġ... ���������Ѵ�...
bool handled[101][1000001] = { false };//dp ��� �ʿ� ���� ��

void Solver(int citem, int cweight) {

	//std::cout << "solver" << citem << " " << cweight << std::endl;

	if (!handled[citem][cweight]) {

		if (citem == 1) {

			if (cweight >= weight[citem]) {
				memory[citem][cweight] = value[citem];
			}
			else{
				memory[citem][cweight] = 0;
			}

			//std::cout << "���� �ִ밡ġ " << memory[citem][cweight] << std::endl;

		}
		else {

			Solver(citem - 1, cweight - weight[citem] > 0 ? cweight - weight[citem] : 0);//�ڱ� ���Ը� ������ ���� ������ �ִ밪
			Solver(citem - 1, cweight);//�ڱ� ���Ը� ������ ���� ������ �ִ밪

			if (cweight >= weight[citem]) {
				memory[citem][cweight] = std::max(memory[citem - 1][cweight], memory[citem - 1][cweight - weight[citem]] + value[citem]);
			}
			else {
				memory[citem][cweight] = memory[citem - 1][cweight];
			}

			//std::cout << "���� �ִ밡ġ " << memory[citem][cweight] << std::endl;


		}

		handled[citem][cweight] = true;

	}

}

int main(int argc, char* argv[]) {

	std::iostream::sync_with_stdio(false);

	//�賶 ������ �̷� ������� Ǯ����.
	//�����۵��� �ϳ��ϳ� ������� �����ϴ� �κ������� �����ϰ�, ������ ������ ���� �κ����պ��� �Ʒ��� ������ �����Ѵ�.
	//�ش� ������ ���԰� 0�� ������ ���԰� �賶�� ���� �Ѱ���� ���� �� �ִ� �ִ��� ���Ը� ����Ѵ�.
	//��, ����� �̷��� �̷������.
	//1. ���� �������� ���� �� �ִ� ��ġ �� �ڽ��� ���Ը� ������ �Ͱ� ������ ���� �� �� ����Ѵ�.
	//2. �ڽ��� ���Ը� ������ �Ͱ� ������ �� �� ��ġ�� �� ũ�� ���� �� �ִ� ���� ����.
	//��� �κ����տ� ���ؼ� �� ������ �ݺ��Ѵ�.

	//�츮�� �ʿ��� �ุ ����ϴ� ������ �˰����� ����� ���̴�.
	//dpǮ�̴� ��� ĭ�� ���ؼ� ������ �����ϹǷ� ����� ��������.
	//���������� �޸𸮸� ũ�� ���� ������ �ᱹ �ߺ������� �Ѵ�.
	//�� ���� �������� �ذ��ϱ� ���ؼ�, �޸������̼��� �ϴ� ��� �������� ����� ����Ѵ�.
	int n = 0, k = 0;
	std::cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		std::cin >> weight[i] >> value[i];
	}

	Solver(n, k);

	std::cout << memory[n][k] << std::endl;

	return 0;

}