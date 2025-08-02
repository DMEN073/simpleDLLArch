import ctypes

lib = ctypes.CDLL("/home/kaiping/code/simpleDLLArchi/lib/libenglish.so")
lib.create_speaker.restype = ctypes.c_void_p
lib.speaker_say.argtypes = [ctypes.c_void_p]
lib.destroy_speaker.argtypes = [ctypes.c_void_p]

obj = lib.create_speaker()
lib.speaker_say(obj)
lib.destroy_speaker(obj)
