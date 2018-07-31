namespace genericTimer {

	void initHardware(int clkHz) {
		target::STK.RVR.setRELOAD(clkHz / 100L);
		target::STK.CVR.setCURRENT(0);
		target::STK.CSR.setTICKINT(1);
		target::STK.CSR.setCLKSOURCE(1);
		target::STK.CSR.setENABLE(1);
	}

}

void interruptHandlerSysTick() {
	applicationEvents::schedule(genericTimer::eventId);
}
