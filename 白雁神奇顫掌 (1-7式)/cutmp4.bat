REM https://youtu.be/aHl6isqtWz8 

REM 00:00:13-00:01:29
ffmpeg -ss 00:00:13 -t 00:01:16 -i "videoplayback.mp4" -vcodec copy -acodec copy  "01.mp4"

REM 00:02:38-00:04:35
ffmpeg -ss 00:02:38 -t 00:01:57 -i "videoplayback.mp4" -vcodec copy -acodec copy  "02.mp4"

REM 00:04:48-00:07:42
ffmpeg -ss 00:04:48 -t 00:02:54 -i "videoplayback.mp4" -vcodec copy -acodec copy  "03.mp4"

REM 00:07:50-00:10:00
ffmpeg -ss 00:07:50 -t 00:02:10 -i "videoplayback.mp4" -vcodec copy -acodec copy  "04.mp4"

REM 00:11:36-00:12:40
ffmpeg -ss 00:11:36 -t 00:01:04 -i "videoplayback.mp4" -vcodec copy -acodec copy  "05.mp4"

REM 00:14:10-00:17:27
ffmpeg -ss 00:14:10 -t 00:03:17 -i "videoplayback.mp4" -vcodec copy -acodec copy  "06.mp4"

REM 00:17:38-00:20:43
ffmpeg -ss 00:17:38 -t 00:03:05 -i "videoplayback.mp4" -vcodec copy -acodec copy  "07.mp4"

pause
