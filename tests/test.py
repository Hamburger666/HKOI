import time
import progressbar

with progressbar.ProgressBar(max_value=100) as bar:
    for i in range(102):
        time.sleep(0.01)
        try:
            bar.update(i)
        except:
            pass