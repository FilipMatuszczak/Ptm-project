# Instrument muzyczny zrealizowany na STM-32
Projekt na zajęcia z Podstaw Techniki Mikroprocesorowej.
# 1. Opis ogólny
Projekt to, jak łatwo się domyślić, instrument muzyczny z 16 klawiszami, któremu brzmieniem najbliżej do gitary elektrycznej z mocnym przesterem.  Instrument ma bardzo unikalny wygląd, ze względu na jego futurystyczne, podświetlane klawisze. Za pomocą prostej aplikacji użytkownik może zmieniać kolor podświetlenia. Dodatkową bardzo ciekawą funkcjonalnością instrumentu jest możliwość nauki różnych piosenek, która polega na tym, że instrument podświetla każdy kolejny klawisz, który należy kliknąć, żeby poprawnie odegrać zadaną piosenkę.
# 2. Użyte peryferia:
- Klawiatura z 16 przyciskami
- Płytka elektroniczna do przycisków
- 2 okrągłe głośniki
- Wzmacniacz do głośników z regulowaną głośnością
- Przekaźnik USB USART
- 16 diód RGB ze wspólną anodą
- Części drewniane oraz kable
# 3. IDE
Do programowania mikrokontrolera użyto Eclipse for C/C++ Developers updated to STM32 Workbench.
Do programowania aplikacji użyto Netbeansa, razem z frameworkiem Spring oraz bibliotekę RxTx do komunikacji USB.
# 4. Problemy z jakimi zetknęliśmy się podczas pracy:
- STM32 domyślnie nie umie używać funkcji sin i należy zmienić parę opcji w ustawieniach projektu, żeby tworzenie sinusoidy zadziałało.
Oto co należy zmienić:
project -> properties -> c build -> settings -> hardware = no unit | ABI = soft
- Przy wykrywaniu kliknięcia, mieliśmy spory problem z drganiem styków oraz np. przy wykryciu, czy użytkownik klinął dokładnie 3 razy w ten sam przycisk, czy po prostu przytrzymał go dostatecznie długo. Rozwiązanie to sprawdzanie przez 50ms czy przycisk został puszczony. Człowiek nie jest w stanie tak szybko kliknąć, a my jesteśmy w stanie stwierdzić, że na pewno puścił przycisk albo kliknął go kolejny raz.
- Instalacja biblioteki RxTx w Netbeans. Rozwiązanie pod tym linkiem - http://rxtx.qbang.org/wiki/index.php/Using_RXTX_In_NetBeans
# 5. Autorzy:
- Filip Matuszczak
- Bartosz Mila
