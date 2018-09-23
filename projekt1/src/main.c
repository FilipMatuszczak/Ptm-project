#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
volatile double scaled = 4;
int flaga = 0;
int licznik = 0;
int prz = 0;
volatile double glob2 = 0;
volatile double glob3 = 0;
int licznik69 = 0;
volatile double sinus;
int poprzedni_przycisk = 0;
int przycisk = 0;
const int kotek_size1 = 18;
const int kotek_size = 51;
int kotek[] = { 5, 3, 3, 4, 2, 2, 1, 3, 5, 5, 3, 3, 4, 2, 2, 1, 3, 1 };
int current_size = 51;
int koko[] = { 8, 8, 4, 6, 6, 5, 8, 8, 4, 6, 6, 5, 8, 8, 4, 6, 6, 5, 3, 5, 2, 4,
		3, 1, 1, 1, 1, 1, 1, 5, 3, 4, 4, 4, 4, 4, 8, 6, 1, 1, 1, 1, 1, 5, 3, 5,
		4, 3, 2, 1, 1 };
int cicha_noc[] = { 5, 6, 5, 3, 5, 6, 5, 3, 9, 9, 7, 7, 8, 8, 5, 6, 6, 8, 7, 6,
		5, 6, 5, 3, 3, 6, 6, 8, 7, 6, 5, 6, 5, 3, 3, 9, 9, 11, 9, 7, 8, 10, 8,
		5, 3, 5, 4, 2, 1 };
int sto_lat[] = { 5, 3, 5, 3, 5, 6, 5, 4, 3, 4, 4, 2, 4, 2, 4, 5, 4, 3, 2, 3, 5,
		5, 3, 5, 5, 3, 5, 8, 7, 6, 5, 6, 7, 7, 7, 8 };
int sweet_child[] = { 1, 8, 5, 4, 11, 5, 10, 5, 1, 8, 5, 4, 11, 5, 10, 5, 2, 8,
		5, 4, 11, 5, 10, 5, 2, 8, 5, 4, 11, 5, 10, 5, 4, 8, 5, 4, 11, 5, 10, 5,
		4, 8, 5, 4, 11, 5, 10, 5, 9, 5, 8, 5, 9, 5, 10, 5, 11, 5, 10, 5, 9, 5,
		8, 5 };
int noc_size = 49;
int child_size = 64;
int stolat_size = 36;
int current_table = 0;
int sprawdzenie;
int learningmode = 0;
int playingmode = 0;
int current_colour = 0;
void USART3_IRQHandler(void) {
	if (USART_GetITStatus(USART3, USART_IT_RXNE) != RESET) {
		char x;
		x = USART_ReceiveData(USART3);

		if (x == 'c') {
			playingmode = 0;
			learningmode = 1;
			current_table = 0;

		}
		if (x == 'a') {
			playingmode = 1;
			learningmode = 0;
		}
		if (playingmode) {
			switch (x) {
			case '1':

				color_in(1);
				break;
			case '2':

				color_in(2);
				break;
			case '3':

				color_in(3);
				break;
			case '4':

				color_in(6);
				break;
			case '5':

				color_in(4);
				break;
			case '6':

				color_in(5);
				break;
			default:
				break;
			}
		}
		if (learningmode) {
			switch (x) {
			case '1':

				current_size = 18;
				current_table = 1;
				licznik = 0;
				break;
			case '2':
				current_size = 51;
				current_table = 2;
				licznik = 0;
				break;
			case '3':
				current_size = 49;
				current_table = 3;
				licznik = 0;
				break;
			case '4':
				current_size = 36;
				current_table = 4;
				licznik = 0;
				break;
			case '5':
				current_size = 64;
				current_table = 5;
				licznik = 0;
				break;
			default:
				break;
			}
		}
	}
}

int check() {
	int x = przycisk;
	switch (x) {
	case 1:
		GPIO_SetBits(GPIOE, GPIO_Pin_9);
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14)) {
			GPIO_ResetBits(GPIOE, GPIO_Pin_9);
			return 1;
		}

		break;
	case 2:
		GPIO_SetBits(GPIOE, GPIO_Pin_9);
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13)) {
			GPIO_ResetBits(GPIOE, GPIO_Pin_9);
			return 2;
		}
		break;
	case 3:
		GPIO_SetBits(GPIOE, GPIO_Pin_9);
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12)) {
			GPIO_ResetBits(GPIOE, GPIO_Pin_9);
			return 3;
		}
		break;
	case 4:
		GPIO_SetBits(GPIOE, GPIO_Pin_9);
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11)) {
			GPIO_ResetBits(GPIOE, GPIO_Pin_9);
			return 4;
		}
		break;
	case 5:
		GPIO_SetBits(GPIOE, GPIO_Pin_11);
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14)) {
			GPIO_ResetBits(GPIOE, GPIO_Pin_11);
			return 5;
		}
		break;
	case 6:
		GPIO_SetBits(GPIOE, GPIO_Pin_11);
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13)) {
			GPIO_ResetBits(GPIOE, GPIO_Pin_11);
			return 6;
		}
		break;
	case 7:
		GPIO_SetBits(GPIOE, GPIO_Pin_11);
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12)) {
			GPIO_ResetBits(GPIOE, GPIO_Pin_11);
			return 7;
		}
		break;
	case 8:
		GPIO_SetBits(GPIOE, GPIO_Pin_11);
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11)) {
			GPIO_ResetBits(GPIOE, GPIO_Pin_11);
			return 8;
		}
		break;
	case 9:
		GPIO_SetBits(GPIOE, GPIO_Pin_13);
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14)) {
			GPIO_ResetBits(GPIOE, GPIO_Pin_13);
			return 9;
		}
		break;
	case 10:
		GPIO_SetBits(GPIOE, GPIO_Pin_13);
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13)) {
			GPIO_ResetBits(GPIOE, GPIO_Pin_13);
			return 10;
		}
		break;
	case 11:
		GPIO_SetBits(GPIOE, GPIO_Pin_13);
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12)) {
			GPIO_ResetBits(GPIOE, GPIO_Pin_13);
			return 11;
		}
		break;
	case 12:
		GPIO_SetBits(GPIOE, GPIO_Pin_13);
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11)) {
			GPIO_ResetBits(GPIOE, GPIO_Pin_13);
			return 12;
		}
		break;
	case 13:
		GPIO_SetBits(GPIOE, GPIO_Pin_15);
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14)) {
			GPIO_ResetBits(GPIOE, GPIO_Pin_15);
			return 13;
		}
		break;
	case 14:
		GPIO_SetBits(GPIOE, GPIO_Pin_15);
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13)) {
			GPIO_ResetBits(GPIOE, GPIO_Pin_15);
			return 14;
		}
		break;
	case 15:
		GPIO_SetBits(GPIOE, GPIO_Pin_15);
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12)) {
			GPIO_ResetBits(GPIOE, GPIO_Pin_15);
			return 15;
		}
		break;
	case 16:
		GPIO_SetBits(GPIOE, GPIO_Pin_15);
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11)) {
			GPIO_ResetBits(GPIOE, GPIO_Pin_15);
			return 16;
		}
		break;

	}
	return 0;
}

void enableTimer4(int prz) {
	if (flaga == 0) {
		przycisk = prz;
		flaga = 1;
		TIM_Cmd(TIM4, ENABLE);
	}
}
void setDACdata(double freq) {
	glob3 = freq;
	DAC_SetChannel1Data(DAC_Align_12b_R, sinus);
	DAC_SetChannel2Data(DAC_Align_12b_R, sinus);
}
void checkKey() {
	GPIO_ResetBits(GPIOB,
	GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14);
	for (int i = 0; i < 50; i++) {
	}

	GPIO_SetBits(GPIOE, GPIO_Pin_9);
	for (int i = 0; i < 50; i++) {
	}

	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14)) {
		setDACdata(0.00997);
		enableTimer4(1);
	} else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13)) {
		setDACdata(0.01121);
		enableTimer4(2);
	} else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12)) {
		setDACdata(0.01255);
		enableTimer4(3);
	} else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11)) {
		setDACdata(0.01333);
		enableTimer4(4);
	}

	for (int i = 0; i < 50; i++) {
	}
	GPIO_ResetBits(GPIOE, GPIO_Pin_9);
	GPIO_SetBits(GPIOE, GPIO_Pin_11);
	for (int i = 0; i < 50; i++) {
	}

	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14)) {
		setDACdata(0.01495);
		enableTimer4(5);
	} else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13)) {
		setDACdata(0.01675);
		enableTimer4(6);
	} else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12)) {
		setDACdata(0.0188);
		enableTimer4(7);
	} else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11)) {
		setDACdata(0.01997);
		enableTimer4(8);
	}

	for (int i = 0; i < 50; i++) {
	}
	GPIO_ResetBits(GPIOE, GPIO_Pin_11);
	GPIO_SetBits(GPIOE, GPIO_Pin_13);
	for (int i = 0; i < 50; i++) {
	}

	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14)) {
		setDACdata(0.0224);
		enableTimer4(9);
	}

	else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13)) {
		setDACdata(0.0251);
		enableTimer4(10);
	}

	else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12)) {
		setDACdata(0.0266);
		enableTimer4(11);
	}

	else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11)) {
		setDACdata(0.02983);
		enableTimer4(12);
	}

	for (int i = 0; i < 50; i++) {
	}
	GPIO_ResetBits(GPIOE, GPIO_Pin_13);
	GPIO_SetBits(GPIOE, GPIO_Pin_15);
	for (int i = 0; i < 50; i++) {
	}

	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14)) {
		setDACdata(0.0335);
		enableTimer4(13);
	}

	else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13)) {
		setDACdata(0.0376);
		enableTimer4(14);
	}

	else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12)) {
		setDACdata(0.0399);
		enableTimer4(15);
	}

	else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11)) {
		setDACdata(0.04481);
		enableTimer4(16);
	}

	GPIO_ResetBits(GPIOE, GPIO_Pin_15);
	for (int i = 0; i < 50; i++) {
	}
}
void the_end_of_song() {
	color_in(2);
	for (int i = 0; i < 500000; i++) {
	}
	color_in(0);
	for (int i = 0; i < 500000; i++) {
	}
	color_in(2);
	for (int i = 0; i < 500000; i++) {
	}
	color_in(0);
	for (int i = 0; i < 500000; i++) {
	}
}
void checkDiode(int przy) {
	switch (current_table) {
	case 1:
		if (przy > 0 && licznik <= current_size - 1
				&& (przy == kotek[licznik])) {
			licznik++;
		}
		break;
	case 2:
		if (przy > 0 && licznik <= current_size - 1
				&& (przy == koko[licznik])) {
			licznik++;
		}
		break;
	case 3:
		if (przy > 0 && licznik <= current_size - 1
				&& (przy == cicha_noc[licznik])) {
			licznik++;
		}
		break;
	case 4:
		if (przy > 0 && licznik <= current_size - 1
				&& (przy == sto_lat[licznik])) {
			licznik++;
		}
		break;
	case 5:
		if (przy > 0 && licznik <= current_size - 1
				&& (przy == sweet_child[licznik])) {
			licznik++;
		}
		break;
	}

}

void TIM3_IRQHandler(void) {
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET) {
		if (TIM_GetFlagStatus(TIM3, TIM_FLAG_Update)) {
			checkKey();
			glob2 = glob2 + glob3;
			if (glob2 > 1.7E+307) {
				glob2 = 0.0;
			}
			sinus = ((1 + sin(glob2 * 6.28)) * 2221) * scaled / 2.95;
			TIM_ClearFlag(TIM3, TIM_FLAG_Update);
		}
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
	}
}

void TIM4_IRQHandler(void) {

	if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET) {
		if (TIM_GetFlagStatus(TIM4, TIM_FLAG_Update)) {

			prz = check(przycisk);
			if (licznik69 < 50 && przycisk == prz) {
				flaga = 0;
				licznik69 = 0;
				poprzedni_przycisk = przycisk;
				TIM_Cmd(TIM4, DISABLE);
				TIM_SetCounter(TIM4, 0);
			} else if (licznik69 < 50 && przycisk != prz) {
				licznik69++;
				TIM_ClearFlag(TIM4, TIM_FLAG_Update);
			} else if (licznik69 >= 50) {
				checkDiode(poprzedni_przycisk);
				flaga = 0;
				licznik69 = 0;
				poprzedni_przycisk = przycisk;
				TIM_Cmd(TIM4, DISABLE);
				TIM_SetCounter(TIM4, 0);
			}
			poprzedni_przycisk = przycisk;
		}
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
	}
}

void color_in(int in_what) {
	switch (in_what) {
	case 1: //red
		GPIO_ResetBits(GPIOC,
		GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_5);
		GPIO_SetBits(GPIOD, GPIO_Pin_6 | GPIO_Pin_3 | GPIO_Pin_1 | GPIO_Pin_0);
		GPIO_SetBits(GPIOB, GPIO_Pin_5 | GPIO_Pin_4 | GPIO_Pin_1 | GPIO_Pin_0);

		GPIO_ResetBits(GPIOD, GPIO_Pin_7 | GPIO_Pin_2); //SET//RED
		GPIO_ResetBits(GPIOB, GPIO_Pin_7 | GPIO_Pin_8);
		GPIO_SetBits(GPIOC, GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_5);

		break;

	case 2: //green
		GPIO_ResetBits(GPIOC,
		GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_5); //RESET//RESET
		GPIO_SetBits(GPIOD, GPIO_Pin_7 | GPIO_Pin_3 | GPIO_Pin_2 | GPIO_Pin_0);
		GPIO_SetBits(GPIOB, GPIO_Pin_7 | GPIO_Pin_4 | GPIO_Pin_8 | GPIO_Pin_0);

		GPIO_ResetBits(GPIOD, GPIO_Pin_6 | GPIO_Pin_1); //SET//GREEN
		GPIO_ResetBits(GPIOB, GPIO_Pin_5 | GPIO_Pin_1);
		GPIO_SetBits(GPIOC, GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_5);

		break;

	case 3: //blue
		GPIO_ResetBits(GPIOC,
		GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_5); //RESET//RESET
		GPIO_SetBits(GPIOD, GPIO_Pin_7 | GPIO_Pin_6 | GPIO_Pin_2 | GPIO_Pin_1);
		GPIO_SetBits(GPIOB, GPIO_Pin_7 | GPIO_Pin_5 | GPIO_Pin_8 | GPIO_Pin_1);

		GPIO_ResetBits(GPIOD, GPIO_Pin_3 | GPIO_Pin_0); //SET//BLUE
		GPIO_ResetBits(GPIOB, GPIO_Pin_4 | GPIO_Pin_0);
		GPIO_SetBits(GPIOC, GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_5);

		break;

	case 4: //yellow
		GPIO_ResetBits(GPIOC,
		GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_5); //RESET//RESET
		GPIO_SetBits(GPIOD, GPIO_Pin_3 | GPIO_Pin_0);
		GPIO_SetBits(GPIOB, GPIO_Pin_4 | GPIO_Pin_0);

		GPIO_ResetBits(GPIOD,
		GPIO_Pin_7 | GPIO_Pin_2 | GPIO_Pin_6 | GPIO_Pin_1); //SET//RED//GREEN
		GPIO_ResetBits(GPIOB,
		GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_5 | GPIO_Pin_1);
		GPIO_SetBits(GPIOC, GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_5);

		break;

	case 5: //cyan
		GPIO_ResetBits(GPIOC,
		GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_5); //RESET//RESET
		GPIO_SetBits(GPIOD, GPIO_Pin_7 | GPIO_Pin_2);
		GPIO_SetBits(GPIOB, GPIO_Pin_7 | GPIO_Pin_8);

		GPIO_ResetBits(GPIOD,
		GPIO_Pin_6 | GPIO_Pin_1 | GPIO_Pin_3 | GPIO_Pin_0); //SET//GREEN//BLUE
		GPIO_ResetBits(GPIOB,
		GPIO_Pin_5 | GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_0);
		GPIO_SetBits(GPIOC, GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_5);

		break;

	case 6: //violet
		GPIO_ResetBits(GPIOC,
		GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_5); //RESET//RESET
		GPIO_SetBits(GPIOD, GPIO_Pin_6 | GPIO_Pin_1);
		GPIO_SetBits(GPIOB, GPIO_Pin_5 | GPIO_Pin_1);

		GPIO_ResetBits(GPIOD,
		GPIO_Pin_7 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_0); //SET//RED//BLUE
		GPIO_ResetBits(GPIOB,
		GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_4 | GPIO_Pin_0);
		GPIO_SetBits(GPIOC, GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_5);

		break;

	case 7: //white
		GPIO_ResetBits(GPIOC,
		GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_5); //RESET

		GPIO_ResetBits(GPIOD,
				GPIO_Pin_7 | GPIO_Pin_2 | GPIO_Pin_6 | GPIO_Pin_1 | GPIO_Pin_3
						| GPIO_Pin_0); //SET//RED//GREEN//BLUE
		GPIO_ResetBits(GPIOB,
				GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_5 | GPIO_Pin_1 | GPIO_Pin_4
						| GPIO_Pin_0);
		GPIO_SetBits(GPIOC, GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_5); //SET

		break;

	case 0: //void
		GPIO_ResetBits(GPIOC,
		GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_5); //RESET//RESET
		GPIO_SetBits(GPIOD,
				GPIO_Pin_7 | GPIO_Pin_6 | GPIO_Pin_3 | GPIO_Pin_2 | GPIO_Pin_1
						| GPIO_Pin_0);
		GPIO_SetBits(GPIOB,
				GPIO_Pin_7 | GPIO_Pin_5 | GPIO_Pin_4 | GPIO_Pin_8 | GPIO_Pin_1
						| GPIO_Pin_0);

		break;

	default:

		break;

	}
}
void diode_light(int song[]) {
	switch (song[licznik]) {
	case 1:

		GPIO_ResetBits(GPIOD, GPIO_Pin_6);

		GPIO_SetBits(GPIOB,
				GPIO_Pin_7 | GPIO_Pin_5 | GPIO_Pin_4 | GPIO_Pin_8 | GPIO_Pin_1
						| GPIO_Pin_0);
		GPIO_SetBits(GPIOD,
		GPIO_Pin_7 | GPIO_Pin_3 | GPIO_Pin_2 | GPIO_Pin_1 | GPIO_Pin_0);

		GPIO_SetBits(GPIOC, GPIO_Pin_1);
		GPIO_ResetBits(GPIOC, GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_5);
		break;
	case 2:
		GPIO_ResetBits(GPIOD, GPIO_Pin_6);

		GPIO_SetBits(GPIOB,
				GPIO_Pin_7 | GPIO_Pin_5 | GPIO_Pin_4 | GPIO_Pin_8 | GPIO_Pin_1
						| GPIO_Pin_0);
		GPIO_SetBits(GPIOD,
		GPIO_Pin_7 | GPIO_Pin_3 | GPIO_Pin_2 | GPIO_Pin_1 | GPIO_Pin_0);

		GPIO_SetBits(GPIOC, GPIO_Pin_2);
		GPIO_ResetBits(GPIOC, GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_5);
		break;
	case 3:
		GPIO_ResetBits(GPIOD, GPIO_Pin_6);

		GPIO_SetBits(GPIOB,
				GPIO_Pin_7 | GPIO_Pin_5 | GPIO_Pin_4 | GPIO_Pin_8 | GPIO_Pin_1
						| GPIO_Pin_0);
		GPIO_SetBits(GPIOD,
		GPIO_Pin_7 | GPIO_Pin_3 | GPIO_Pin_2 | GPIO_Pin_1 | GPIO_Pin_0);

		GPIO_SetBits(GPIOC, GPIO_Pin_4);
		GPIO_ResetBits(GPIOC, GPIO_Pin_2 | GPIO_Pin_1 | GPIO_Pin_5);
		break;
	case 4:
		GPIO_ResetBits(GPIOD, GPIO_Pin_6);

		GPIO_SetBits(GPIOB,
				GPIO_Pin_7 | GPIO_Pin_5 | GPIO_Pin_4 | GPIO_Pin_8 | GPIO_Pin_1
						| GPIO_Pin_0);
		GPIO_SetBits(GPIOD,
		GPIO_Pin_7 | GPIO_Pin_3 | GPIO_Pin_2 | GPIO_Pin_1 | GPIO_Pin_0);

		GPIO_SetBits(GPIOC, GPIO_Pin_5);
		GPIO_ResetBits(GPIOC, GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_1);
		break;
	case 5:
		GPIO_ResetBits(GPIOD, GPIO_Pin_1);

		GPIO_SetBits(GPIOB,
				GPIO_Pin_7 | GPIO_Pin_5 | GPIO_Pin_4 | GPIO_Pin_8 | GPIO_Pin_1
						| GPIO_Pin_0);
		GPIO_SetBits(GPIOD,
		GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_3 | GPIO_Pin_2 | GPIO_Pin_0);

		GPIO_SetBits(GPIOC, GPIO_Pin_1);
		GPIO_ResetBits(GPIOC, GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_5);
		break;
	case 6:
		GPIO_ResetBits(GPIOD, GPIO_Pin_1);

		GPIO_SetBits(GPIOB,
				GPIO_Pin_7 | GPIO_Pin_5 | GPIO_Pin_4 | GPIO_Pin_8 | GPIO_Pin_1
						| GPIO_Pin_0);
		GPIO_SetBits(GPIOD,
		GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_3 | GPIO_Pin_2 | GPIO_Pin_0);

		GPIO_SetBits(GPIOC, GPIO_Pin_2);
		GPIO_ResetBits(GPIOC, GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_5);
		break;
	case 7:
		GPIO_ResetBits(GPIOD, GPIO_Pin_1);

		GPIO_SetBits(GPIOB,
				GPIO_Pin_7 | GPIO_Pin_5 | GPIO_Pin_4 | GPIO_Pin_8 | GPIO_Pin_1
						| GPIO_Pin_0);
		GPIO_SetBits(GPIOD,
		GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_3 | GPIO_Pin_2 | GPIO_Pin_0);

		GPIO_SetBits(GPIOC, GPIO_Pin_4);
		GPIO_ResetBits(GPIOC, GPIO_Pin_2 | GPIO_Pin_1 | GPIO_Pin_5);
		break;
	case 8:
		GPIO_ResetBits(GPIOD, GPIO_Pin_1);

		GPIO_SetBits(GPIOB,
				GPIO_Pin_7 | GPIO_Pin_5 | GPIO_Pin_4 | GPIO_Pin_8 | GPIO_Pin_1
						| GPIO_Pin_0);
		GPIO_SetBits(GPIOD,
		GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_3 | GPIO_Pin_2 | GPIO_Pin_0);

		GPIO_SetBits(GPIOC, GPIO_Pin_5);
		GPIO_ResetBits(GPIOC, GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_1);
		break;
	case 9:
		GPIO_ResetBits(GPIOB, GPIO_Pin_5);

		GPIO_SetBits(GPIOB,
		GPIO_Pin_7 | GPIO_Pin_4 | GPIO_Pin_8 | GPIO_Pin_1 | GPIO_Pin_0);
		GPIO_SetBits(GPIOD,
				GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_3 | GPIO_Pin_2 | GPIO_Pin_1
						| GPIO_Pin_0);

		GPIO_SetBits(GPIOC, GPIO_Pin_1);
		GPIO_ResetBits(GPIOC, GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_5);
		break;
	case 10:
		GPIO_ResetBits(GPIOB, GPIO_Pin_5);

		GPIO_SetBits(GPIOB,
		GPIO_Pin_7 | GPIO_Pin_4 | GPIO_Pin_8 | GPIO_Pin_1 | GPIO_Pin_0);
		GPIO_SetBits(GPIOD,
				GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_3 | GPIO_Pin_2 | GPIO_Pin_1
						| GPIO_Pin_0);

		GPIO_SetBits(GPIOC, GPIO_Pin_2);
		GPIO_ResetBits(GPIOC, GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_5);
		break;
	case 11:
		GPIO_ResetBits(GPIOB, GPIO_Pin_5);

		GPIO_SetBits(GPIOB,
		GPIO_Pin_7 | GPIO_Pin_4 | GPIO_Pin_8 | GPIO_Pin_1 | GPIO_Pin_0);
		GPIO_SetBits(GPIOD,
				GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_3 | GPIO_Pin_2 | GPIO_Pin_1
						| GPIO_Pin_0);

		GPIO_SetBits(GPIOC, GPIO_Pin_4);
		GPIO_ResetBits(GPIOC, GPIO_Pin_2 | GPIO_Pin_1 | GPIO_Pin_5);
		break;
	case 12:
		GPIO_ResetBits(GPIOB, GPIO_Pin_5);

		GPIO_SetBits(GPIOB,
		GPIO_Pin_7 | GPIO_Pin_4 | GPIO_Pin_8 | GPIO_Pin_1 | GPIO_Pin_0);
		GPIO_SetBits(GPIOD,
				GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_3 | GPIO_Pin_2 | GPIO_Pin_1
						| GPIO_Pin_0);

		GPIO_SetBits(GPIOC, GPIO_Pin_5);
		GPIO_ResetBits(GPIOC, GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_1);
		break;
	case 13:
		GPIO_ResetBits(GPIOB, GPIO_Pin_1);

		GPIO_SetBits(GPIOB,
		GPIO_Pin_7 | GPIO_Pin_5 | GPIO_Pin_4 | GPIO_Pin_8 | GPIO_Pin_0);
		GPIO_SetBits(GPIOD,
				GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_3 | GPIO_Pin_2 | GPIO_Pin_1
						| GPIO_Pin_0);

		GPIO_SetBits(GPIOC, GPIO_Pin_1);
		GPIO_ResetBits(GPIOC, GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_5);
		break;
	case 14:
		GPIO_ResetBits(GPIOB, GPIO_Pin_1);

		GPIO_SetBits(GPIOB,
		GPIO_Pin_7 | GPIO_Pin_5 | GPIO_Pin_4 | GPIO_Pin_8 | GPIO_Pin_0);
		GPIO_SetBits(GPIOD,
				GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_3 | GPIO_Pin_2 | GPIO_Pin_1
						| GPIO_Pin_0);

		GPIO_SetBits(GPIOC, GPIO_Pin_2);
		GPIO_ResetBits(GPIOC, GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_5);
		break;
	case 15:
		GPIO_ResetBits(GPIOB, GPIO_Pin_1);

		GPIO_SetBits(GPIOB,
		GPIO_Pin_7 | GPIO_Pin_5 | GPIO_Pin_4 | GPIO_Pin_8 | GPIO_Pin_0);
		GPIO_SetBits(GPIOD,
				GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_3 | GPIO_Pin_2 | GPIO_Pin_1
						| GPIO_Pin_0);

		GPIO_SetBits(GPIOC, GPIO_Pin_4);
		GPIO_ResetBits(GPIOC, GPIO_Pin_2 | GPIO_Pin_1 | GPIO_Pin_5);
		break;
	case 16:
		GPIO_ResetBits(GPIOB, GPIO_Pin_1);

		GPIO_SetBits(GPIOB,
		GPIO_Pin_7 | GPIO_Pin_5 | GPIO_Pin_4 | GPIO_Pin_8 | GPIO_Pin_0);
		GPIO_SetBits(GPIOD,
				GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_3 | GPIO_Pin_2 | GPIO_Pin_1
						| GPIO_Pin_0);

		GPIO_SetBits(GPIOC, GPIO_Pin_5);
		GPIO_ResetBits(GPIOC, GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_1);
		break;
	default:

		break;
	}

}
int main(void) {

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure2;
	GPIO_InitStructure2.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
	GPIO_InitStructure2.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure2.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure2.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure2.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure2);
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource10, GPIO_AF_USART3);
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource11, GPIO_AF_USART3);

	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate = 9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl =
	USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

	NVIC_InitTypeDef NVIC_InitStructure2;
	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
	NVIC_InitStructure2.NVIC_IRQChannel = USART3_IRQn;
	NVIC_InitStructure2.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure2.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure2.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure2);
	NVIC_EnableIRQ(USART3_IRQn);

	USART_Init(USART3, &USART_InitStructure);
	USART_Cmd(USART3, ENABLE);

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure1;

	GPIO_InitStructure1.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_4;
	GPIO_InitStructure1.GPIO_Mode = GPIO_Mode_AN;
	GPIO_InitStructure1.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure1.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &GPIO_InitStructure1);

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);
	DAC_InitTypeDef DAC_InitStructure;

	DAC_InitStructure.DAC_Trigger = DAC_Trigger_None;
	DAC_InitStructure.DAC_WaveGeneration = DAC_WaveGeneration_None;
	DAC_InitStructure.DAC_LFSRUnmask_TriangleAmplitude =
	DAC_LFSRUnmask_Bit0;
	DAC_InitStructure.DAC_OutputBuffer = DAC_OutputBuffer_Enable;
	DAC_Init(DAC_Channel_1, &DAC_InitStructure);
	DAC_Cmd(DAC_Channel_1, ENABLE);
	DAC_Init(DAC_Channel_2, &DAC_InitStructure);
	DAC_Cmd(DAC_Channel_2, ENABLE);

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Period = 31;
	TIM_TimeBaseStructure.TIM_Prescaler = 99;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
	TIM_Cmd(TIM3, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_4
			| GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_8
			| GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2
			| GPIO_Pin_3 | GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_11 | GPIO_Pin_13
			| GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOE, &GPIO_InitStructure);

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13
			| GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure2;
	TIM_TimeBaseStructure2.TIM_Period = 83;
	TIM_TimeBaseStructure2.TIM_Prescaler = 999;
	TIM_TimeBaseStructure2.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure2.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure2);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	NVIC_InitTypeDef NVIC_InitStructure3;
	NVIC_InitStructure3.NVIC_IRQChannel = TIM4_IRQn;
	NVIC_InitStructure3.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStructure3.NVIC_IRQChannelSubPriority = 0x00;
	NVIC_InitStructure3.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure3);
	TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
	TIM_Cmd(TIM4, DISABLE);

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14
			| GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	GPIO_SetBits(GPIOB,
			GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_8 | GPIO_Pin_4 | GPIO_Pin_5
					| GPIO_Pin_7);
	GPIO_SetBits(GPIOD,
			GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_6
					| GPIO_Pin_7);
	for (;;) {
		if (learningmode) {
			switch (current_table) {
			case 1:
				diode_light(kotek);
				break;
			case 2:
				diode_light(koko);
				break;
			case 3:
				diode_light(cicha_noc);
				break;
			case 4:
				diode_light(sto_lat);
				break;
			case 5:
				diode_light(sweet_child);
				break;
			default:
				break;
			}
		}
		if (licznik == current_size) {
			the_end_of_song();
			learningmode = 0;
			licznik = 0;
		}
	}

}
