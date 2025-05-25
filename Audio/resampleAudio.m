clc; clear; close all;

% Read audio file
[y, fs] = wavread('audio1.wav');

% Resample to half the sampling rate (downsample by 2)
y_resampled = resample(y, 1, 2);

% New sampling frequency
fs_new = fs / 2;

% Play original audio
disp('Playing original audio...');
sound(y, fs);
pause(length(y)/fs + 1);

% Play resampled audio
disp('Playing resampled audio...');
sound(y_resampled, fs_new);

% Save resampled audio
wavwrite(y_resampled, fs_new, 'resampled_output.wav');
disp('Resampled audio saved as resampled_output.wav');
