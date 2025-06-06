clc; close all; clear all;

[y, fs] = wavread('audio1.wav');  % Read audio data and sampling frequency
disp(['Sampling rate: ', num2str(fs)]);
disp('Audio Playing');
sound(y, fs);  % Play audio

wavwrite(y, fs, 'output.wav');  % Save audio data to output.wav

disp('Audio saved as output.wav');
  