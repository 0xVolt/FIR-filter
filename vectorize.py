import wave
import struct

def wavToFloat(wave_file):
    w = wave.open(wave_file)
    astr = w.readframes(w.getnframes())
    
    # convert binary chunks to short 
    a = struct.unpack("%ih" % (w.getnframes() * w.getnchannels()), astr)
    
    # a = [float(val) / pow(2, 15) for val in a]
    a = [float(val) for val in a]
    
    return a

def main():
    signal = wavToFloat(r'data/wrong-place-sound.wav')
    
    print("# Frames Read:", str(len(signal)))
    print(f"Range of Values: [{str(min(signal))}, {str(max(signal))}]")
    
    print(type(signal))
    
if __name__ == '__main__':
    main()