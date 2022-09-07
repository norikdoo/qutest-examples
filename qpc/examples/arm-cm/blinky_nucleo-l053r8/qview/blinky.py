class Blinky:
    def __init__(self):

        # add commands to the Custom menu...
        QView.custom_menu.add_command(label="Custom command",
                                      command=self.cust_command)

        # configure the custom QView.canvas...
        QView.show_canvas() # make the canvas visible
        QView.canvas.configure(width=100, height=100)

        # LED images for UP and DOWN
        self._img = (
            PhotoImage(file=HOME_DIR + "/img/off.png"),
            PhotoImage(file=HOME_DIR + "/img/on.png"),
        )  

        # images of a button for pause/serve
        self._led = QView.canvas.create_image(50, 50, image=self._img[0])
        reset_target()

    # on_reset() callback
    def on_reset(self):
        # clear the lists
        # self._philo_obj   = [0, 0, 0, 0, 0]
        self._blinky_state = 0

    # on_run() callback
    def on_run(self):
        glb_filter("QS_USER_00")

    # example of a custom command
    def cust_command(self):
        command(1, 12345)

    # Intercept the QS_USER_00 application-specific trace record.
    # This record has the following structure (see bsp.c:displayPhilStat()):
    # Seq-Num, Record-ID, Timestamp, format-byte, Philo-num,
    #    format-byte, Zero-terminated string (status)
    def QS_USER_00(self, packet):
        # unpack: Timestamp->data[0], Philo-num->data[1], status->data[3]
        data = qunpack("xxTxBxZ", packet)
        j = ("F", "N").index(data[2][1]) # the first letter
        # animate the LED
        QView.canvas.itemconfig(self._led, image=self._img[j])

        # print a message to the text view
        QView.print_text("%s"%(data[2]))

#=============================================================================
QView.customize(Blinky()) # set the QView customization
