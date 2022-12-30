#ifndef WAVE_H
#define WAVE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GROUND 32768.0
#define MAXPLUS 65536.0
#define MAXMINUS 0.0

// モノラルの音声データの定義
typedef struct
{
    // 標本化周波数
    int fs;
    // 量子化制度
    int bits;
    // データ長
    int length;
    // 音データ
    double *s;
} MONO_PCM;

// RIFFチャンクの定義
typedef struct
{
    char chunkID[4];
    long chunkSize;
    char chunkFormType[4];
} RIFF_CHUNK;

// fmtチャンクの定義
typedef struct
{
    char chunkID[4];
    long chunkSize;
    short waveFormatType;
    short formatChannel;
    long samplesPerSec;
    long bytesPerSec;
    short blockSize;
    short bitsPerSample;
} FMT_CHUNK;

// dataチャンクの定義
typedef struct
{
    char chunkID[4];
    long chunkSize;
    short data;
} DATA_CHUNK;

// WAVEフォーマット
typedef struct
{
    RIFF_CHUNK riffChunk;
    FMT_CHUNK fmtChunk;
    DATA_CHUNK dataChunk;
} WAVE_FORMAT;

// モノラルの音声データ(waveファイル)の読み込み
void monoWaveRead(MONO_PCM *pcm, char *fileName);

// モノラルの音声データ(waveファイル)書き込み
void monoWaveWrite(MONO_PCM *pcm, char *fileName);


#endif
