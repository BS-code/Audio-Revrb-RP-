# Audio-Revrb-RP
Contoh program dalam bahasa C++ untuk Arduino yang menggunakan Modul ADC dan Modul PWM untuk membuat efek Reverb:

Program mengambil masukan analog dari pin ADC dan mengeluarkan efek Reverb melalui output PWM. Program ini menggunakan library LedControl untuk mengontrol output PWM. Loop utama dalam program menambahkan efek reverb pada sinyal audio dengan menggunakan lookup table sinusoid. Anda dapat menyesuaikan parameter SAMPLES dan DELAY_MS untuk memperoleh efek reverb yang berbeda. Selain itu, Anda juga dapat menyesuaikan parameter PWM_FREQ untuk meningkatkan kualitas audio.
