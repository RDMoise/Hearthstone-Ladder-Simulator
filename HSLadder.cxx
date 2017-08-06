void HSLadder( Double_t winrate){
	Int_t trials = 1000;
	TRandom3 *rng = new TRandom3(1);
	TCanvas *c = new TCanvas();
	TH1D *h = new TH1D("","",100,0,5000);
	for(Int_t i=0;i<trials;i++){
		Int_t AcquiredStars = 10; //rank 20: 10, 15: 25
		Int_t NMatches = 0;
		Int_t Streak = 0;
		while(AcquiredStars < 96){
			Double_t match = rng->Uniform(0,1);
			NMatches++;
			if(match < winrate) {//win
				AcquiredStars++;
				Streak++;
				if(Streak>2 && AcquiredStars < 71) AcquiredStars++;
			}
			else{//loss
				if(AcquiredStars > 10) AcquiredStars--;
				Streak = 0;
			}
		}
		h->Fill(NMatches);
	}
	h->Draw();
	h->GetXaxis()->SetTitle("Matches to legend");
}