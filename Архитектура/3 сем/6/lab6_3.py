import ffmpeg

def add_subtitles(input_video: str, subtitles_file: str, output_video: str):
    try:
        (
            ffmpeg
            .input(input_video)
            .output(output_video, vf=f"subtitles={subtitles_file}")
            .run(overwrite_output=True)
        )
        print(f"Субтитры успешно добавлены в файл: {output_video}")
    except ffmpeg.Error as e:
        print("Ошибка при добавлении субтитров:")
        print(e.stderr.decode())

# Пример использования:
if __name__ == "__main__":
    input_video = 'input2.mp4'
    subtitles_file = 'subtitles.srt'
    output_video = 'output_with_subs.mp4'

    add_subtitles(input_video, subtitles_file, output_video)
