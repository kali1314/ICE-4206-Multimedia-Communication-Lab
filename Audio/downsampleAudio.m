clc; clear; close all;

% Read audio file
[y, fs] = wavread('audio1.wav');

% Downsample factor (e.g., reduce sampling rate by 10)
factor = 10;

% Downsample audio signal by factor
y_down = downsample(y, factor);

% New sampling rate after downsampling
fs_new = fs / factor;

% Play original audio
disp('Playing original audio...');
sound(y, fs);
pause(length(y)/fs + 1);

% Play downsampled audio
disp('Playing downsampled audio...');
sound(y_down, fs_new);

% Save downsampled audio
wavwrite(y_down, fs_new, 'downsampled_output.wav');
disp('Downsampled audio saved as downsampled_output.wav');
