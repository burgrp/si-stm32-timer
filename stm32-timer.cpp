namespace genericTimer {

	int clkHz = 8E6;

	void initHardware() {
		target::SYSTICK.RVR.setRELOAD(clkHz / 100L);
		target::SYSTICK.CVR.setCURRENT(0);

		// this is error in SVD - DISABLE_SYSTICK_EXCEPTION and ENABLE_SYSTICK_EXCEPTION are swapped
		// hence we use integer value here
		// target::systick::CSR::TICKINT::DISABLE_SYSTICK_EXCEPTION
		// target::systick::CSR::TICKINT::ENABLE_SYSTICK_EXCEPTION
		target::SYSTICK.CSR.setTICKINT((target::systick::CSR::TICKINT)1);
		
		target::SYSTICK.CSR.setCLKSOURCE(target::systick::CSR::CLKSOURCE::CPU_CLOCK);
		target::SYSTICK.CSR.setENABLE(target::systick::CSR::ENABLE::ENABLED);
		
	}

}

void interruptHandlerSysTick() {
	applicationEvents::schedule(genericTimer::eventId);
}
