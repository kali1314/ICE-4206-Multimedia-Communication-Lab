clc;
clear;
close all;

% Read Image (replace path accordingly)
img = imread('D:\\Jontrona\\4.2\\ICE-4206_Multimedia_Communication_Lab\\Image\\image1.jpeg');
figure, imshow(img); title('Original Image');

% Resize Image
resizedImg = imresize(img, 0.5);
figure, imshow(resizedImg); title('Resized Image');

% Crop Image
croppedImg = imcrop(resizedImg, [50 50 150 150]);
figure, imshow(croppedImg); title('Cropped Image');

% Save Image
imwrite(croppedImg, 'cropped_output.jpg');

% Image Information
info = imfinfo('cropped_output.jpg');
disp(info);

% Convert to Grayscale
if size(resizedImg,3) == 3
    grayImg = rgb2gray(resizedImg);
else
    grayImg = resizedImg;
end
figure, imshow(grayImg); title('Grayscale Image');

% Histogram
figure, imhist(grayImg); title('Histogram');

% Edge Detection (Canny)
edges = edge(grayImg, 'canny');
figure, imshow(edges); title('Canny Edges');

% Hough Transform
[H, theta, rho] = hough(edges);
figure, imshow(imadjust(mat2gray(H)), 'XData', theta, 'YData', rho, ...
    'InitialMagnification', 'fit');
title('Hough Transform');
xlabel('\theta'), ylabel('\rho');

% ginput safe use
figHandle = figure;
imshow(resizedImg);
title('Click a pixel on the image');
[x, y] = ginput(1);
if isempty(x)
    disp('No click detected.');
else
    pixelVal = impixel(resizedImg, round(x), round(y));
    disp(['Pixel value at (', num2str(round(x)), ',', num2str(round(y)), '): ', mat2str(pixelVal)]);
end

% Binarize Image (no imbinarize)
level = graythresh(grayImg);
BW = im2bw(grayImg, level);

% Connected components (use bwlabel)
[L, numComponents] = bwlabel(BW);
disp(['Number of connected components: ', num2str(numComponents)]);

% MSE manual calculation
diff = double(grayImg) - double(grayImg);
mse_val = mean(diff(:).^2);
disp(['MSE (same image): ', num2str(mse_val)]);

% DCT and IDCT
dctImg = dct2(double(grayImg));
idctImg = idct2(dctImg);
figure, imshow(uint8(idctImg)); title('IDCT of DCT Image');

% Sobel Filtering
h = fspecial('sobel');
filteredImg = imfilter(grayImg, h);
figure, imshow(filteredImg); title('Filtered Image (Sobel)');

% Gaussian Filter (fspecial + imfilter)
h_gauss = fspecial('gaussian', [5 5], 2);
gaussianImg = imfilter(grayImg, h_gauss, 'same');
figure, imshow(gaussianImg); title('Gaussian Filtered Image');

% Gabor filter not available
disp('Gabor filtering not supported in MATLAB R2007b.');

% Create Movie Frames
frames(1) = im2frame(img);
frames(2) = im2frame(resizedImg);
frames(3) = im2frame(croppedImg);
movie(frames, 1, 1);

% Montage fix for R2007b: Create 4D uint8 array
imgs = zeros(size(img,1), size(img,2), size(img,3), 4, 'uint8'); 

imgs(:,:,:,1) = imresize(img, [size(img,1), size(img,2)]);
imgs(:,:,:,2) = imresize(resizedImg, [size(img,1), size(img,2)]);
% Resize cropped image to match original size for montage
croppedResized = imresize(croppedImg, [size(img,1), size(img,2)]);
imgs(:,:,:,3) = croppedResized;
% For grayscale, replicate channel 3 times
grayRgb = repmat(grayImg, [1 1 3]);
imgs(:,:,:,4) = imresize(grayRgb, [size(img,1), size(img,2)]);

figure, montage(imgs);
title('Montage View');

% Save Image Dialog
imsave;

% Rotate Image
rotatedImg = imrotate(grayImg, 45);
figure, imshow(rotatedImg); title('Rotated Image');

% Erase selected region
figure, imshow(grayImg); title('Select area to erase');
BWerase = roipoly(grayImg);
erasedImg = grayImg;
erasedImg(BWerase) = 255;
figure, imshow(erasedImg); title('Erased Selected Region');

disp('? All operations completed successfully!');
