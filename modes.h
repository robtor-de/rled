void mode_loop() {
  if(F_FAILSTATE && !F_FAILSTATESWITCHED) {
    load_startup_color();
  }
}
