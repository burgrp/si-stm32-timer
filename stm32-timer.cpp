namespace genericTimer {

	void initHardware() {
		target::STK.RVR.setRELOAD(8E6 / 100L);
		target::STK.CVR.setCURRENT(0);
		target::STK.CSR.setTICKINT(1);
		target::STK.CSR.setCLKSOURCE(1);
		target::STK.CSR.setENABLE(1);
	}

}

void interruptHandlerSysTick() {
	applicationEvents::schedule(genericTimer::eventId);
}
