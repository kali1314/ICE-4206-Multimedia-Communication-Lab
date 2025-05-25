clc; clear; close all;
% Read audio (mono)
[y, fs] = wavread('audio1.wav');
if size(y,2) > 1
    y = y(:,1); % use only one channel if stereo
end

% Compute DCT of the audio
y_dct = dct(y);
% Compute IDCT (reconstruct the signal)
y_idct = idct(y_dct);

% Play original audio
disp('Playing original audio...');
sound(y, fs);
pause(length(y)/fs + 1); % wait for audio to finish
% Play audio from DCT
disp('Playing audio from DCT...');
sound(y_dct, fs);
% Play reconstructed audio from IDCT
disp('Playing reconstructed audio from IDCT...');
sound(y_idct, fs);
